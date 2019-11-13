#include <cstdlib>
#include <iostream>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file
#include <boost/test/unit_test.hpp>
#include "../src/vec3.h"

static float f[7] = {0.0f, 1.432f, -7.345f, 45.85f, 1000.0f, 23425425.34f, -555.553f};

BOOST_AUTO_TEST_CASE( vector_addition ) {
    vec3 a = vec3(f[1], f[2], f[3]);
    vec3 b = vec3(f[4], f[5], f[6]);

    vec3 ab = a + b;

    BOOST_CHECK(ab.x == a.x + b.x);
    BOOST_CHECK(ab.y == a.y + b.y);
    BOOST_CHECK(ab.z == a.z + b.z);
}

BOOST_AUTO_TEST_CASE( vector_substraction ) {
    vec3 a = vec3(f[1], f[2], f[3]);
    vec3 b = vec3(f[4], f[5], f[6]);

    vec3 ab = a - b;

    BOOST_CHECK(ab.x == a.x - b.x);
    BOOST_CHECK(ab.y == a.y - b.y);
    BOOST_CHECK(ab.z == a.z - b.z);
}

BOOST_AUTO_TEST_CASE( scalar_right_multiplication ) {
    vec3 a = vec3(f[1], f[2], f[3]);
    float s = f[5];

    vec3 ab = a * s;

    BOOST_CHECK(ab.x == a.x * s);
    BOOST_CHECK(ab.y == a.y * s);
    BOOST_CHECK(ab.z == a.z * s);
}

BOOST_AUTO_TEST_CASE( scalar_left_multiplication ) {
    vec3 a = vec3(f[1], f[2], f[3]);
    float s = f[5];

    vec3 ab = s * a;

    BOOST_CHECK_EQUAL(ab.x, s * a.x);
    BOOST_CHECK_EQUAL(ab.y, s * a.y);
    BOOST_CHECK_EQUAL(ab.z, s * a.z);
}

BOOST_AUTO_TEST_CASE( norm2 ) {
    vec3 a = vec3(f[1], f[2], f[3]);
    float expected = f[1] * f[1] + f[2] * f[2] + f[3] * f[3];

    float result = a.norm2();

    BOOST_CHECK_EQUAL(expected, result);
}

BOOST_AUTO_TEST_CASE( copy_assignment ) {
    vec3 a = vec3(f[2], f[4], f[6]);
    vec3 b = vec3(f[0], f[0], f[0]);

    b = a;

    BOOST_CHECK_EQUAL(a.x, b.x);
    BOOST_CHECK_EQUAL(a.y, b.y);
    BOOST_CHECK_EQUAL(a.z, b.z);
}

BOOST_AUTO_TEST_CASE( copy_assignment_mutation ) {
    vec3 a = vec3(f[2], f[4], f[6]);
    vec3 b = vec3(f[0], f[0], f[0]);
    b = a;

    b.x = f[1];

    BOOST_CHECK(a.x != b.x);
}

BOOST_AUTO_TEST_CASE( normalized ) {
    vec3 a = vec3(f[2], f[4], f[6]);

    a = a.normalized();

    BOOST_CHECK_EQUAL(a.norm(), 1.0f);
}