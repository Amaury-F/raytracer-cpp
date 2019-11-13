#ifndef RAYTRACER_IMG_H
#define RAYTRACER_IMG_H

#include "vec3.h"
#include <string>


class Img {
public:

    Img(size_t width, size_t height);
    ~Img();

    void write(const std::string &name);

    const size_t width;
    const size_t height;

    vec3 **data;

    int to8bit(float n);
};



#endif //RAYTRACER_IMG_H