#include <iostream>
#include "vec3.h"
#include "Img.h"

int main() {

    Img img = Img(600, 400);

    vec3 center = vec3(300, 80, 0);
    float radius = 50;


    for (size_t i = 0; i < img.width; ++i) {
        for (size_t j = 0; j < img.height; ++j) {
            vec3 pixel;
            vec3 pos = vec3((float) i, (float) j, 0);

            float dist = (center - pos).norm();

            if (dist < radius) {
                pixel.r = (float) i / (float) img.width;
                pixel.g = (float) j / (float) img.height;
            } else {
                pixel.b = (float) i / (float) img.width;
                pixel.r = (float) j / (float) img.height;

            }

            img.data[i][j] = pixel;
        }
    }

    img.write("image.ppm");

    return 0;
}