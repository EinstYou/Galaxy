cmake_minimum_required(VERSION 4.1)
project(Galaxy)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(Classes)
add_subdirectory(SDL)
add_subdirectory(SDL_image)
add_subdirectory(SDL_ttf)


add_executable(Galaxy main.cpp)
target_link_libraries(Galaxy PUBLIC Classes)
target_link_libraries(Galaxy PUBLIC SDL3::SDL3)
target_link_libraries(Galaxy PUBLIC SDL3_image::SDL3_image)
target_link_libraries(Galaxy PUBLIC SDL3_ttf::SDL3_ttf)
