#include "camera.h"
#include "ray.h"
#include "renderer.h"

#include <cstdint>

Renderer::Renderer(const Scene& scene)
    : m_scene(scene)
{
    m_pixels.resize(m_scene.getCamera().getImageWidth() * m_scene.getCamera().getImageHeight());
}

Renderer::~Renderer() = default;

void Renderer::render()
{
    const auto& camera = m_scene.getCamera();
    const uint32_t width = camera.getImageWidth();
    const uint32_t height = camera.getImageHeight();
    constexpr int max_depth = 8;

    for (uint32_t i = 0; i < height; ++i) {
        for (uint32_t j = 0; j < width; ++j) {
            auto ray = camera.getRay(i, j);
            auto color = trace(ray, max_depth);
            m_pixels[i * width + j] = color * 255.0f;
        }
    }
}

const std::vector<Vec3>& Renderer::getPixels() const
{
    return m_pixels;
}

Vec3 Renderer::trace(const Ray& ray, int depth) const
{
    if (depth <= 0) {
        return Vec3{0.0f, 0.0f, 0.0f};
    }

    HitRecord hit_record = closestHit(ray);
    if (!hit_record.is_hit) {
        return backgroundColor(ray);
    }

    if (hit_record.material == nullptr) {
        return Vec3{1.0f, 0.0f, 1.0f};
    }

    return hit_record.material->shade(ray, hit_record, *this, depth);
}

HitRecord Renderer::closestHit(const Ray& ray) const
{
    HitRecord closest_hit;
    float closest_t = 1e30f;

    for (auto& object : m_scene.getObjects()) {
        HitRecord hit_record = object->hit(ray);
        if (hit_record.is_hit && hit_record.t < closest_t) {
            closest_t = hit_record.t;
            closest_hit = hit_record;
        }
    }

    return closest_hit;
}

bool Renderer::isInShadow(const Vec3& point, const Vec3& normal, const Vec3& light_position) const
{
    Vec3 to_light = light_position - point;
    float light_distance = to_light.length();
    Vec3 shadow_direction = unitVector(to_light);
    Ray shadow_ray{point + normal * 1e-4f, shadow_direction};

    for (auto& object : m_scene.getObjects()) {
        HitRecord hit_record = object->hit(shadow_ray);
        if (hit_record.is_hit && hit_record.t < light_distance) {
            return true;
        }
    }

    return false;
}

Vec3 Renderer::backgroundColor(const Ray& ray) const
{
    Vec3 direction = unitVector(ray.getDirection());
    float t = 0.5f * (direction.y() + 1.0f);
    return (1.0f - t) * Vec3{1.0f, 1.0f, 1.0f} + t * Vec3{0.45f, 0.7f, 1.0f};
}
