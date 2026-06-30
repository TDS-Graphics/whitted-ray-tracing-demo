#include "ppm_writer.h"

#include <cstdint>

#include <fstream>
#include <iostream>

PPMWriter::PPMWriter(const std::string& file_name, uint32_t width, uint32_t height)
    : m_image_width(width),
      m_image_height(height),
      m_file_name(file_name)
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
        uint8_t r = static_cast<uint8_t>(std::clamp(data[i].x(), 0.0f, 255.0f));
        uint8_t g = static_cast<uint8_t>(std::clamp(data[i].y(), 0.0f, 255.0f));
        uint8_t b = static_cast<uint8_t>(std::clamp(data[i].z(), 0.0f, 255.0f));

        ofs.write(reinterpret_cast<const char*>(&r), 1);
        ofs.write(reinterpret_cast<const char*>(&g), 1);
        ofs.write(reinterpret_cast<const char*>(&b), 1);
    }

    ofs.close();
    std::cout << "Saved image to: " << m_file_name << std::endl;
}

void PPMWriter::setFileName(const std::string& file_name)
{
    m_file_name = file_name;
}

void PPMWriter::setImageSize(uint32_t width, uint32_t height)
{
    m_image_width = width;
    m_image_height = height;
}
