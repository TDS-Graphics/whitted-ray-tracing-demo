#pragma once

#include "object.h"
#include "ray.h"

class Sphere : public Object {
public:
    Sphere(const Vec3& center, float radius)
        : m_center(center),
          m_radius(radius)
    {}

    virtual ~Sphere() = default;

    virtual HitRecord hit(const Ray& ray) const override
    {
        Vec3 oc = ray.getOrigin() - m_center;
        float a = dot(ray.getDirection(), ray.getDirection());
        float b = 2.0 * dot(oc, ray.getDirection());
        float c = dot(oc, oc) - m_radius * m_radius;
        float discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            float sqrt_disc = std::sqrt(discriminant);
            float t1 = (-b - sqrt_disc) / (2.0 * a);
            float t2 = (-b + sqrt_disc) / (2.0 * a);

            float t = t1 < t2 ? t1 : t2;
            if (t > 1e-8) {
                Vec3 hit_position = ray.at(t);
                return HitRecord{true, t, hit_position, hit_position - m_center};
            }
        }
        return HitRecord{false};
    }

private:
    Vec3 m_center;
    float m_radius;
};
