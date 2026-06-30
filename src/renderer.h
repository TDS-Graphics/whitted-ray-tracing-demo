#pragma once
#include "math/vec3.h"
#include "scene.h"

#include <vector>

class Renderer {
public:
    explicit Renderer(const Scene& scene);
    ~Renderer();

    void render();

    const std::vector<Vec3>& getPixels() const;

    Vec3 trace(const Ray& ray, int depth) const;
    HitRecord closestHit(const Ray& ray) const;
    bool isInShadow(const Vec3& point, const Vec3& normal, const Vec3& light_position) const;
    Vec3 backgroundColor(const Ray& ray) const;

private:
    const Scene& m_scene;
    std::vector<Vec3> m_pixels;
};
