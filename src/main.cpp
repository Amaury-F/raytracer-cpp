#include <iostream>
#include "vec3.h"
#include "ray.h"
#include "Img.h"

vec3 color(const ray& r) {
    vec3 sky_color = vec3(0.5f, 0.7f, 1.0f);

    vec3 unit_direction = r.dir.normalized();
    float t = 0.5f * (unit_direction.y + 1.0f);
    return (1.0f - t) * vec3(1.0f, 1.0f, 1.0f) + t * sky_color;
}


int main() {
    int nx = 200;
    int ny = 100;

    Img image = Img(static_cast<size_t>(nx), static_cast<size_t>(ny));

    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    for (int y = ny - 1, j = 0; y >= 0; --y) {
        for (int x = 0, i = 0;  x < nx; ++x) {

            float u = float(x) / float(nx);
            float v = float(y) / float(ny);

            ray r(origin, lower_left_corner + u*horizontal + v*vertical);

            vec3 col = color(r);

            image.data[i][j] = col;

            ++i;
        }
        ++j;
    }

    image.write("result.ppm");
}