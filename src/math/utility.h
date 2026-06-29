#pragma once
inline unsigned char clamp(float value, float minVal, float maxVal)
{
    if (value < minVal) {
        return static_cast<unsigned char>(minVal);
    }
    if (value > maxVal) {
        return static_cast<unsigned char>(maxVal);
    }
    return static_cast<unsigned char>(value);
}
