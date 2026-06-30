#include "sphere.h"

#include "ray.h"

#include <cmath>
#include <utility>

Sphere::Sphere(const Vec3& center, float radius, std::shared_ptr<const Material> material)
    : Object(std::move(material)),
      m_center(center),
      m_radius(radius)
{}


HitRecord Sphere::hit(const Ray& ray) const
{
    Vec3 oc = ray.getOrigin() - m_center;
    float a = dot(ray.getDirection(), ray.getDirection());
    float b = 2.0f * dot(oc, ray.getDirection());
    float c = dot(oc, oc) - m_radius * m_radius;
    float discriminant = b * b - 4.0f * a * c;

    if (discriminant > 0.0f) {
        float sqrt_disc = std::sqrt(discriminant);
        float t1 = (-b - sqrt_disc) / (2.0f * a);
        float t2 = (-b + sqrt_disc) / (2.0f * a);

        float t = t1;
        if (t <= 1e-4f) {
            t = t2;
        }

        if (t > 1e-4f) {
            Vec3 hit_position = ray.at(t);
            return HitRecord{true, t, hit_position, unitVector(hit_position - m_center), m_material.get()};
        }
    }

    return HitRecord{false};
}
