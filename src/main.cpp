#include <iostream>
#include "vec3.h"

int main() {

    vec3 oui = vec3(1, 2, 3);


    std::cout << oui.x << std::endl;
    float &a = oui.x;
    a = 3;
    std::cout << oui.x << std::endl;

    return 0;
}