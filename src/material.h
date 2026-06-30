#pragma once

#include "math/vec3.h"

class Ray;
class Renderer;
struct HitRecord;

class Material {
public:
    virtual ~Material() = default;

    virtual Vec3 shade(const Ray& ray, const HitRecord& hit_record, const Renderer& renderer, int depth) const = 0;
};

class Lambertian : public Material {
public:
    explicit Lambertian(const Vec3& albedo);

    Vec3 shade(const Ray& ray, const HitRecord& hit_record, const Renderer& renderer, int depth) const override;

private:
    Vec3 m_albedo;
};

class Mirror : public Material {
public:
    explicit Mirror(const Vec3& albedo);

    Vec3 shade(const Ray& ray, const HitRecord& hit_record, const Renderer& renderer, int depth) const override;

private:
    Vec3 m_albedo;
};
