#include <iostream>
#include <cmath>

#include "../lib/Function.h"

Function::Function() {}

Function::~Function() {}

void Function::drow(int width, int height){

    for (int y = height; y >= -height; --y) {
        for (int x = -width; x <= width; ++x) {
            double fx = sin(x * 0.1); // функція
            int graphY = static_cast<int>(fx * height);
            if (graphY == y) {
                std::cout << '*';
            } else if (y == 0) {
                std::cout << '-';
            } else if (x == 0) {
                std::cout << '|';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}