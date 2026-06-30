// main.cpp
#include "math/vec3.h"
#include "ppm_writer.h"
#include "renderer.h"
#include "camera.h"
#include "scene.h"

#include <vector>

int main()
{
    const unsigned int image_width = 800;
    const unsigned int image_height = 800;
    
    Camera camera(image_width, image_height);
    camera.setPosition(Vec3(0.0f, 0.0f, 1.0f));

    Scene scene(camera);
    scene.addSphere(Vec3(0.0f, 0.0f, 0.0f), 0.5f);

    Renderer renderer(scene);
    renderer.render();

    std::vector<Vec3> frame_buffer = renderer.getPixels();

    PPMWriter writer("output1.ppm", image_width, image_height);
    writer.save(frame_buffer);

    return 0;
}
