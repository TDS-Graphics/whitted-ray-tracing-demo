#include "math/utility.h"
#include "ppm_writer.h"

#include <fstream>
#include <iostream>

PPMWriter::PPMWriter(const std::string& fileName, unsigned int width, unsigned int height)
    : m_image_width(width),
      m_image_height(height),
      m_file_name(fileName)
{}

PPMWriter::~PPMWriter() = default;

void PPMWriter::save(const std::vector<Vec3>& data)
{
    if (data.size() != static_cast<std::size_t>(m_image_width * m_image_height)) {
        std::cerr << "Warning: data size doesn't match image dimensions" << std::endl;
        return;
    }

    std::ofstream ofs(m_file_name.c_str(), std::ios::binary);

    if (!ofs.is_open()) {
        std::cerr << "Failed to open file: " << m_file_name << std::endl;
        return;
    }

    ofs << "P6\n" << m_image_width << " " << m_image_height << "\n255\n";

    for (std::size_t i = 0; i < data.size(); ++i) {
        unsigned char r = clamp(data[i].x(), 0.0f, 255.0f);
        unsigned char g = clamp(data[i].y(), 0.0f, 255.0f);
        unsigned char b = clamp(data[i].z(), 0.0f, 255.0f);

        ofs.write((const char*) (&r), 1);
        ofs.write((const char*) (&g), 1);
        ofs.write((const char*) (&b), 1);
    }

    ofs.close();
    std::cout << "Saved image to: " << m_file_name << std::endl;
}

void PPMWriter::setFileName(const std::string& fileName)
{
    m_file_name = fileName;
}

void PPMWriter::setImageSize(unsigned int width, unsigned int height)
{
    m_image_width = width;
    m_image_height = height;
}
