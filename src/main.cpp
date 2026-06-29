#include <iostream>
#include "math/vec3.h"
int main() {
    std::cout << "Hello, Whitted-Style Ray Tracing!" << std::endl;

    // TODO: Remove this test block 
    std::cout << "============YOU NEED DELETE THIS==========="<< std::endl;
    Vec3 a(1.0f, 2.0f, 3.0f);
    Vec3 b(4.0f, 5.0f, 6.0f);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
    std::cout << "a - b: " << a - b << std::endl;
    std::cout << "a * b: " << a * b << std::endl;
    
    std::cout << "a * 2.0f: " << a * 2.0f << std::endl;
    std::cout << "2.0f * a: " << 2.0f * a << std::endl;
    std::cout << "a / 2.0f: " << a / 2.0f << std::endl;

    std::cout << "a.length(): " << a.length() << std::endl;
    std::cout << "a.lengthSquared(): " << a.lengthSquared() << std::endl;

    std::cout << "unitVector(a): " << unitVector(a) << std::endl;

    std::cout << "dot(a, b): " << dot(a, b) << std::endl;
    std::cout << "cross(a, b): " << cross(a, b) << std::endl;

    std::cout << "a.nearZero(): " << a.nearZero() << std::endl;

    std::cout << "a.x(): " << a.x() << std::endl;
    std::cout << "a.y(): " << a.y() << std::endl;
    std::cout << "a.z(): " << a.z() << std::endl;

    std::cout << "============YOU NEED DELETE THIS==========="<< std::endl;
    return 0;
}