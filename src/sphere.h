#pragma once

#include "object.h"

#include <memory>

class Sphere : public Object {
public:
    Sphere(const Vec3& center, float radius, std::shared_ptr<const Material> material);
    ~Sphere() override = default;

    HitRecord hit(const Ray& ray) const override;

private:
    Vec3 m_center;
    float m_radius;
};
