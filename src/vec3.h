#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

#include <iostream>
#include <cmath>

class vec3 {
public:

    float e[3];

    float &x;
    float &y;
    float &z;

    float &r;
    float &g;
    float &b;

    vec3(float e0, float e1, float e2) : e{e0, e1, e2}, x(e[0]), y(e[1]), z(e[2]), r(e[0]), g(e[1]), b(e[2]) {}
    vec3(): e{0.0f, 0.0f, 0.0f}, x(e[0]), y(e[1]), z(e[2]), r(e[0]), g(e[1]), b(e[2]) {}

    inline const vec3& operator+() const {
        return *this;
    }
    inline vec3 operator-() const {
        return vec3(-x, -y, -z);
    }

    inline float operator[](int i) const {
        return e[i];
    }
    inline float& operator[](int i) {
        return e[i];
    }

    float norm() const;
    float norm2() const;
    vec3 normalized() const;

    vec3& operator+=(const vec3 &v2);
    vec3& operator-=(const vec3 &v2);
    vec3& operator*=(const vec3 &v2);
    vec3& operator/=(const vec3 &v2);
    vec3& operator*=(float t);
    vec3& operator/=(float t);
    vec3& operator=(const vec3 &v2);
};

//binary operators
vec3 operator+(const vec3 &v1, const vec3 &v2);
vec3 operator-(const vec3 &v1, const vec3 &v2);
vec3 operator*(const vec3 &v1, const vec3 &v2);
vec3 operator*(const float t, const vec3 &v);
vec3 operator*(const vec3 &v, float t);
vec3 operator/(const vec3 &v1, const vec3 &v2);
vec3 operator/(vec3 v, float t);
float dot(const vec3 &v1, const vec3 &v2);
vec3 cross(const vec3 &v1, const vec3 &v2);


// read / write
std::istream& operator>>(std::istream &is, vec3 &t);
std::ostream& operator<<(std::ostream &os, const vec3 &t);

#endif //RAYTRACER_VEC3_H