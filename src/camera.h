#pragma once

#include "math/vec3.h"
#include "ray.h"

#include <cstdint>


class Camera {
public:
    Camera() = default;
    Camera(uint32_t image_width, uint32_t image_height);
    ~Camera() = default;

    Ray getRay(float i, float j) const;

    void setPosition(const Vec3& position);
    void setTarget(const Vec3& target);
    void setUp(const Vec3& up);

    uint32_t getImageWidth() const;
    uint32_t getImageHeight() const;
    void setImageSize(uint32_t width, uint32_t height);

private:
    Vec3 m_position;
    Vec3 m_target;
    Vec3 m_up;

    uint32_t m_image_width;
    uint32_t m_image_height;
};
