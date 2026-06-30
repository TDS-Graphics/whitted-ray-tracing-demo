#include "camera.h"

Camera::Camera(uint32_t image_width, uint32_t image_height)
    : m_image_width(image_width),
      m_image_height(image_height),
      m_position({0.0f, 0.0f, 1.0f}),
      m_target({0.0f, 0.0f, 0.0f}),
      m_up({0.0f, 1.0f, 0.0f})
{}

Ray Camera::getRay(float i, float j) const
{
    // The computed results can be cached for optimization.
    Vec3 forward = unitVector(m_target - m_position);
    Vec3 right = unitVector(cross(forward, m_up));
    Vec3 up = unitVector(cross(right, forward));

    float aspect = (float) m_image_width / m_image_height;
    float viewport_height = 2.0f;
    float viewport_width = aspect * viewport_height;

    Vec3 horizontal = viewport_width * right;
    Vec3 vertical = viewport_height * -up;

    Vec3 pixel_delta_u = horizontal / (float) m_image_width;
    Vec3 pixel_delta_v = vertical / (float) m_image_height;

    Vec3 viewport_left_top = m_position + forward - horizontal / 2.0f - vertical / 2.0f;
    Vec3 pixel_left_top = viewport_left_top + 0.5f * (pixel_delta_u + pixel_delta_v);

    Vec3 pixel_center = pixel_left_top + pixel_delta_u * i + pixel_delta_v * j;
    Vec3 ray_direction = pixel_center - m_position;

    Ray ray{m_position, ray_direction};

    return ray;
}

void Camera::setPosition(const Vec3& position)
{
    m_position = position;
}

void Camera::setTarget(const Vec3& target)
{
    m_target = target;
}

void Camera::setUp(const Vec3& up)
{
    m_up = up;
}

uint32_t Camera::getImageWidth() const
{
    return m_image_width;
}

uint32_t Camera::getImageHeight() const
{
    return m_image_height;
}

void Camera::setImageSize(unsigned int width, unsigned int height)
{
    m_image_width = width;
    m_image_height = height;
}
