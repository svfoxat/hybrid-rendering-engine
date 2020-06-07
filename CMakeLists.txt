cmake_minimum_required(VERSION 3.15)
project(HybridEngine)

set(CMAKE_CXX_STANDARD 14)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(ThirdParty/glfw)
add_executable(HybridEngine HybridEngine/main.cpp)

target_link_libraries(HybridEngine glfw)

find_package(OpenGL REQUIRED)

target_link_libraries(HybridEngine OpenGL::GL)
