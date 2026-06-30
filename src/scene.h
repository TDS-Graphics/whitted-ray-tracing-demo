#pragma once

#include "camera.h"
#include "object.h"
#include "sphere.h"

#include <memory>
#include <utility>
#include <vector>

class Scene {
public:
    explicit Scene(const Camera& camera)
        : m_camera(camera)
    {}

    ~Scene() = default;

    Scene(Scene&&) = default;
    Scene& operator=(Scene&&) = default;

    void addObject(std::unique_ptr<Object> object)
    {
        m_objects.push_back(std::move(object));
    }

    void addSphere(const Vec3& center, float radius, std::shared_ptr<const Material> material)
    {
        m_objects.push_back(std::make_unique<Sphere>(center, radius, std::move(material)));
    }

    const std::vector<std::unique_ptr<Object>>& getObjects() const
    {
        return m_objects;
    }

    const Camera& getCamera() const
    {
        return m_camera;
    }

private:
    std::vector<std::unique_ptr<Object>> m_objects;
    Camera m_camera;
};
