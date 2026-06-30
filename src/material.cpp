#include "material.h"

#include "object.h"
#include "ray.h"
#include "renderer.h"

#include <algorithm>

Lambertian::Lambertian(const Vec3& albedo)
    : m_albedo(albedo)
{}

Vec3 Lambertian::shade(const Ray& ray, const HitRecord& hit_record, const Renderer& renderer, int depth) const
{
    Vec3 normal = hit_record.normal;
    if (dot(ray.getDirection(), normal) > 0.0f) {
        normal = -normal;
    }

    const Vec3 ambient_color{0.04f, 0.04f, 0.04f};
    const Vec3 light_position{2.0f, 2.0f, 2.0f};
    const Vec3 light_color{1.0f, 1.0f, 1.0f};

    Vec3 color = m_albedo * ambient_color;

    if (!renderer.isInShadow(hit_record.p, normal, light_position)) {
        Vec3 light_direction = unitVector(light_position - hit_record.p);
        float diffuse = std::max(0.0f, dot(normal, light_direction));
        color += m_albedo * light_color * diffuse;
    }

    return color;
}

Mirror::Mirror(const Vec3& albedo)
    : m_albedo(albedo)
{}

Vec3 Mirror::shade(const Ray& ray, const HitRecord& hit_record, const Renderer& renderer, int depth) const
{
    Vec3 normal = hit_record.normal;
    if (dot(ray.getDirection(), normal) > 0.0f) {
        normal = -normal;
    }

    Vec3 direction = unitVector(ray.getDirection());
    Vec3 reflected = direction - 2.0f * dot(direction, normal) * normal;

    Ray reflected_ray{hit_record.p + normal * 1e-4f, reflected};
    return m_albedo * renderer.trace(reflected_ray, depth - 1);
}
