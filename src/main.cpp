#include <iostream>
#include "vec3.h"
#include "Img.h"

int main() {

    Img img = Img(600, 400);

    vec3 center = vec3(300, 200, 0);
    float radius = 50;


    for (size_t i = 0; i < img.width; ++i) {
        for (size_t j = 0; j < img.height; ++j) {
            vec3 pixel;
            vec3 pos = vec3((float) i, (float) j, 0);

            /*
            if ((pos - center).norm() < radius) {
                pixel
            }*/

            img.data[i][j] = pixel;
        }
    }

    img.write("image.ppm");

    return 0;
}