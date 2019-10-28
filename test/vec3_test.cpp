#include <cstdlib>
#include <iostream>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file
#include <boost/test/unit_test.hpp>
#include "../src/vec3.h"

static float f[7] = {0.0f, 1.432f, -7.345f, 45.85f, 1000.0f, 23425425.34f, -555.553f};

BOOST_AUTO_TEST_CASE( should_match_vector_addition ) {
    vec3 a = {f[1], f[2], f[3]};
    vec3 b = {f[4], f[5], f[6]};

    vec3 ab = a + b;

    BOOST_CHECK(ab.x == a.x + b.x);
    BOOST_CHECK(ab.y == a.y + b.y);
    BOOST_CHECK(ab.z == a.z + b.z);
}

BOOST_AUTO_TEST_CASE( should_match_vector_substraction ) {
    vec3 a = {f[1], f[2], f[3]};
    vec3 b = {f[4], f[5], f[6]};

    vec3 ab = a - b;

    BOOST_CHECK(ab.x == a.x - b.x);
    BOOST_CHECK(ab.y == a.y - b.y);
    BOOST_CHECK(ab.z == a.z - b.z);
}

BOOST_AUTO_TEST_CASE( should_match_scalar_right_multiplication ) {
    vec3 a = {f[1], f[2], f[3]};
    float s = f[5];

    vec3 ab = a * s;

    BOOST_CHECK(ab.x == a.x * s);
    BOOST_CHECK(ab.y == a.y * s);
    BOOST_CHECK(ab.z == a.z * s);
}

BOOST_AUTO_TEST_CASE( should_match_scalar_left_multiplication ) {
    vec3 a = {f[1], f[2], f[3]};
    float s = f[5];

    vec3 ab = s * a;

    BOOST_CHECK(ab.x == s * a.x);
    BOOST_CHECK(ab.y == s * a.y);
    BOOST_CHECK(ab.z == s * a.z);
}

BOOST_AUTO_TEST_CASE( should_match_norm2 ) {
    vec3 a = {f[1], f[2], f[3]};
    float s = f[5];

    vec3 ab = s * a;

    BOOST_CHECK(ab.x == s * a.x);
    BOOST_CHECK(ab.y == s * a.y);
    BOOST_CHECK(ab.z == s * a.z);
}
