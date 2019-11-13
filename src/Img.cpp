#include "Img.h"

#include <iostream>
#include <fstream>
#include <algorithm>

#define GAMMA_RESCALE 0

Img::Img(size_t width, size_t height) : width(width), height(height) {
    this->data = new vec3*[this->width];
    for (size_t i = 0; i < this->width; ++i) {
        this->data[i] = new vec3[this->height];
    }
}

Img::~Img() {
    for (size_t i = 0; i < this->width; ++i) {
        delete[] this->data[i];
    }

    delete[] this->data;
}

int Img::to8bit(float n) {

#if GAMMA_RESCALE
    //gamma rescaling
    n = (float) pow(std::clamp(n, 0.0f, 1.0f), (1/2.2));
#endif

    int r = (int) (n * 255);
    return (r > 255) ? 255 : r;
}

std::ostream &operator<<(std::ostream &os, Img &img) {
    for (size_t j = 0; j < img.height; ++j) {
        for (size_t i = 0; i < img.width; ++i) {

            os << img.to8bit(img.data[i][j].r) << ' '
            << img.to8bit(img.data[i][j].g) << ' '
            << img.to8bit(img.data[i][j].b) << ' ';
        }

        os << std::endl;
    }

    return os;
}

void Img::write(const std::string &name) {
    std::ofstream file;
    file.open(name);
    if (! file) {
        throw "Error: Could not open file";
    }



    file << "P3" << std::endl;
    file << this->width << " " << this->height << std::endl;
    file << 255 << std::endl;

    file << *this;

    file.close();
}




