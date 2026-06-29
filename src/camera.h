#pragma once

#include "math/vec3.h"

class Camera {
public:
    Camera(unsigned int viewport_width, unsigned int viewport_height);
    ~Camera() = default;

    Vec3 getRay(float i, float j) const;

    void setPosition(const Vec3& position);
    void setTarget(const Vec3& target);
    void setUp(const Vec3& up);
    
    void setViewportSize(unsigned int width, unsigned int height);

private:
    Vec3 m_position;
    Vec3 m_target;
    Vec3 m_up;

    unsigned int m_viewport_width;
    unsigned int m_viewport_height;
};
