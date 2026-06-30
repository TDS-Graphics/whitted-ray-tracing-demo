#pragma once
#include "material.h"
#include "math/vec3.h"
#include "ray.h"

#include <memory>
#include <utility>

struct HitRecord {
    bool is_hit{false};
    float t{0};
    Vec3 p{0.0f, 0.0f, 0.0f};
    Vec3 normal{0.0f, 0.0f, 0.0f};
    const Material* material{nullptr};
};

class Object {
public:
    explicit Object(std::shared_ptr<const Material> material)
        : m_material(std::move(material))
    {}

    virtual ~Object() = default;
    virtual HitRecord hit(const Ray& ray) const = 0;

protected:
    std::shared_ptr<const Material> m_material;
};
