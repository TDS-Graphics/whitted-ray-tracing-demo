#pragma once
#include "math/vec3.h"

class Ray {
public:
    Ray(const Vec3& origin, const Vec3& direction)
        : m_origin(origin),
          m_direction(direction)
    {}

    Vec3 getOrigin() const
    {
        return m_origin;
    }

    Vec3 getDirection() const
    {
        return m_direction;
    }

    Vec3 at(float t) const
    {
        return m_origin + t * m_direction;
    }

private:
    Vec3 m_origin;
    Vec3 m_direction;
};
