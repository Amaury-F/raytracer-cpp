set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (raytracer_test vec3_test.cpp ../src/vec3.h ../src/vec3.cpp)
target_link_libraries (raytracer_test ${Boost_LIBRARIES})