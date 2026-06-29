cmake_minimum_required(VERSION 3.20)

project(
    whitted_ray_tracing_app
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCE_FILES 
    src/*.cpp
)

message(STATUS "========Found source files:========")
foreach(FILE ${SOURCE_FILES})
    message(STATUS "  ${FILE}")
endforeach()
message(STATUS "===================================")

add_executable(whitted_ray_tracing_app ${SOURCE_FILES})

