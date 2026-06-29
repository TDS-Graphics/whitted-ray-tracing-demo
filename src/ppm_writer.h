#pragma once
#include "math/vec3.h"

#include <string>
#include <vector>

class PPMWriter {
public:
    PPMWriter(const std::string& fileName, unsigned int width, unsigned int height);
    ~PPMWriter();

    // data component should be in the range [0, 255]
    void save(const std::vector<Vec3>& data);

    void setFileName(const std::string& fileName);
    void setImageSize(unsigned int width, unsigned int height);

private:
    unsigned int m_image_width = 0;
    unsigned int m_image_height = 0;
    std::string m_file_name;
};
