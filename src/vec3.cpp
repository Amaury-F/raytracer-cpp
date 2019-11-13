#include "vec3.h"


// unary operators
float vec3::norm() const {
    return sqrtf(this->norm2());
}

float vec3::norm2() const {
    return x*x + y*y + z*z;
}

vec3 vec3::normalized() const {
    float k = 1.0f / this->norm();
    return vec3(k*x, k*y, k*z);
}


// binary operators
vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

vec3 operator*(const float t, const vec3 &v) {
    return vec3(t*v.x, t*v.y, t*v.z);
}

vec3 operator*(const vec3 &v, float t) {
    return vec3(t*v.x, t*v.y, t*v.z);
}

vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

vec3 operator/(vec3 v, float t) {
    return vec3(v.x/t, v.y/t, v.z/t);
}

float dot(const vec3 &v1, const vec3 &v2) {
    return v1.x*v2.x
           + v1.y*v2.y
           + v1.z*v2.z;
}

vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.y * v2.z - v1.z * v2.y,
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x);
}


// mutation operators
vec3& vec3::operator+=(const vec3 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

vec3& vec3::operator-=(const vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

vec3& vec3::operator*=(const vec3 &v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

vec3& vec3::operator*=(const float t) {
    x *= t;
    y *= t;
    z *= t;
    return *this;
}

vec3& vec3::operator/=(const vec3 &v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

vec3& vec3::operator/=(const float t) {
    float k = 1.0f / t;

    x *= k;
    y *= k;
    z *= k;
    return *this;
}

vec3 &vec3::operator=(const vec3 &v2) {
    this->e[0] = v2.e[0];
    this->e[1] = v2.e[1];
    this->e[2] = v2.e[2];

    return *this;
}


// read / write
std::istream& operator>>(std::istream &is, vec3 &t) {
    is >> t.x >> t.y >> t.z;
    return is;
}

std::ostream& operator<<(std::ostream &os, const vec3 &t) {
    os << "{" << t.x << "," << t.y << "," << t.z << "}";
    return os;
}