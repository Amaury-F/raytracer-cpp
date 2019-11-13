#include <cmath>

#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

#endif //RAYTRACER_VEC3_H

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

float vec3::norm() const {
    return sqrtf(this->norm2());
}

float vec3::norm2() const {
    return x*x + y*y + z*z;
}

std::istream& operator>>(std::istream &is, vec3 &t) {
    is >> t.x >> t.y >> t.z;
    return is;
}

std::ostream& operator<<(std::ostream &os, const vec3 &t) {
    os << "{" << t.x << "," << t.y << "," << t.z << "}";
    return os;
}

vec3 vec3::normalized() const {
    float k = 1.0f / this->norm();
    return vec3(k*x, k*y, k*z);
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

inline vec3 operator*(const float t, const vec3 &v) {
    return vec3(t*v.x, t*v.y, t*v.z);
}

inline vec3 operator*(const vec3 &v, float t) {
    return vec3(t*v.x, t*v.y, t*v.z);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

inline vec3 operator/(vec3 v, float t) {
    return vec3(v.x/t, v.y/t, v.z/t);
}

inline float dot(const vec3 &v1, const vec3 &v2) {
    return v1.x*v2.x
           + v1.y*v2.y
           + v1.z*v2.z;
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.y * v2.z - v1.z * v2.y,
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x);
}

inline vec3& vec3::operator+=(const vec3 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline vec3& vec3::operator-=(const vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

inline vec3& vec3::operator*=(const vec3 &v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

inline vec3& vec3::operator*=(const float t) {
    x *= t;
    y *= t;
    z *= t;
    return *this;
}

inline vec3& vec3::operator/=(const vec3 &v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

inline vec3& vec3::operator/=(const float t) {
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
