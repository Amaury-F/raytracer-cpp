cmake_minimum_required(VERSION 3.14)
project(RAYTRACER)

set(CMAKE_CXX_STANDARD 17)

set(ADDITIONAL_FLAGS "-Wpedantic -Wall -Wextra -Wconversion")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_FLAGS}" )

add_subdirectory(test)
add_subdirectory(src)
