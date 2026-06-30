#pragma once
#include "math/vec3.h"

#include <cstdint>

#include <algorithm>
#include <string>
#include <vector>

class PPMWriter {
public:
    PPMWriter(const std::string& file_name, uint32_t width, uint32_t height);
    ~PPMWriter();

    // data component should be in the range [0, 255]
    void save(const std::vector<Vec3>& data);

    void setFileName(const std::string& file_name);
    void setImageSize(uint32_t width, uint32_t height);

private:
    uint32_t m_image_width = 0;
    uint32_t m_image_height = 0;
    std::string m_file_name;
};
