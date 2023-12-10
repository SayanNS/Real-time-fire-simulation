cmake_minimum_required(VERSION 3.27.8)
project(PerlinNoise)

find_package(SDL2 REQUIRED)

include_directories(${project_name} SDL2_INCLUDE_DIRS)

add_executable(${PROJECT_NAME} main.cpp noise.cpp)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2-static)
