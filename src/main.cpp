// main.cpp
#include "math/vec3.h"
#include "ppm_writer.h"
#include <vector>

int main()
{
    const unsigned int image_width = 800;
    const unsigned int image_height = 800;
    std::vector<Vec3> frame_buffer(image_height * image_width, {0.0f, 0.0f, 0.0f});

    for (unsigned int j = 0; j < image_height; ++j) {
        for (unsigned int i = 0; i < image_width; ++i) {
            const float u = float(i) / float(image_width) * 255.0f;
            const float v = float(j) / float(image_height) * 255.0f;
            const Vec3 color(u, v, 0.0f);
            frame_buffer[j * image_width + i] = color;
        }
    }

    PPMWriter writer("output1.ppm", image_width, image_height);
    writer.save(frame_buffer);

    return 0;
}
