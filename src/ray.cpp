#include "ray.h"

ray::ray(const vec3 &origin, const vec3 &direction) :
  origin(origin), dir(direction)
  {}

vec3 ray::point_at_parameter(float t) const {
    return origin + t * dir;
}