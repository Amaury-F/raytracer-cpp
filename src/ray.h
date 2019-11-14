#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "vec3.h"

class ray {
public:
    ray() {}
    ray(const vec3 &origin, const vec3 &direction);

    vec3 point_at_parameter(float t) const;

    vec3 origin;
    vec3 dir;
};


#endif //RAYTRACER_RAY_H
