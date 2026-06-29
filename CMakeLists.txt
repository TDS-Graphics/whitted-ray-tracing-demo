cmake_minimum_required(VERSION 3.20)

project(
    whitted_ray_tracing_app
    VERSION 0.1.0
    LANGUAGES CXX
)

# TODO：你需要将你自行添加的 .cpp 文件添加到 SOURCE_FILES 中
set(SOURCE_FILES 
    src/main.cpp)

add_executable(whitted_ray_tracing_app ${SOURCE_FILES})

