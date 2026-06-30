// main.cpp
#include "camera.h"
#include "material.h"
#include "math/vec3.h"
#include "ppm_writer.h"
#include "renderer.h"
#include "scene.h"

#include <memory>
#include <vector>

int main()
{
    const unsigned int image_width = 1'980;
    const unsigned int image_height = 1'080;

    Camera camera(image_width, image_height);
    camera.setPosition(Vec3(0.0f, 0.0f, 1.0f));

    auto matte = std::make_shared<Lambertian>(Vec3{0.725f, 0.710f, 0.680f});
    auto ground = std::make_shared<Lambertian>(Vec3{0.45f, 0.52f, 0.48f});
    auto mirror = std::make_shared<Mirror>(Vec3{0.92f, 0.94f, 0.96f});

    Scene scene(camera);
    scene.addSphere(Vec3(-0.48f, 0.02f, -0.22f), 0.45f, matte);
    scene.addSphere(Vec3(0.55f, -0.01f, -0.24f), 0.42f, mirror);
    scene.addSphere(Vec3(0.0f, -100.6f, 0.0f), 150.0f, ground);

    Renderer renderer(scene);
    renderer.render();

    std::vector<Vec3> frame_buffer = renderer.getPixels();

    PPMWriter writer("output1.ppm", image_width, image_height);
    writer.save(frame_buffer);

    return 0;
}
