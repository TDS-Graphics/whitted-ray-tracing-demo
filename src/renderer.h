#pragma once
#include "camera.h"
#include "math/vec3.h"
#include "scene.h"

#include <cstdint>

#include <vector>

class Renderer {
public:
    Renderer(const Scene& scene)
        : m_scene(scene)
    {
        m_pixels.resize(m_scene.getCamera().getImageWidth() * m_scene.getCamera().getImageHeight());
    }

    ~Renderer() = default;

    void render()
    {
        const auto& camera = m_scene.getCamera();
        const uint32_t width = camera.getImageWidth();
        const uint32_t height = camera.getImageHeight();
        for (uint32_t i = 0; i < m_scene.getCamera().getImageHeight(); ++i) {
            for (uint32_t j = 0; j < m_scene.getCamera().getImageWidth(); ++j) {
                auto ray = m_scene.getCamera().getRay(i, j);
                auto color = trace(ray);
                m_pixels[i * width + j] = color * 255.0f;
            }
        }
    }

    const std::vector<Vec3>& getPixels() const
    {
        return m_pixels;
    }

private:
    Vec3 trace(const Ray& ray)
    {
        for (auto& object : m_scene.getObjects()) {
            auto hit_record = object->hit(ray);
            if (hit_record.is_hit) {
                return hit_record.normal;
            }
        }
        return Vec3{0.0f, 0.0f, 0.0f};
    }

    const Scene& m_scene;
    std::vector<Vec3> m_pixels;
};
