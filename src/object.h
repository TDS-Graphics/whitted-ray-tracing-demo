#pragma once
#include "math/vec3.h"
#include "ray.h"

struct HitRecord {
    bool is_hit{false};
    float t{0};
    Vec3 p{0.0f, 0.0f, 0.0f};
    Vec3 normal{0.0f, 0.0f, 0.0f};
};

class Object {
public:
    Object() = default;
    virtual ~Object() = default;
    virtual HitRecord hit(const Ray& ray) const = 0;
};
