#include "../lib/Array.h"

Array::Array() {
    this->x = 0;
    this->y = 0;
    array = nullptr;
}

Array::~Array() {
    if (array != nullptr) {
        for (int i = 0; i < x; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }
}

void Array::setArray(int valueX, int valueY) {
    this->x = valueX;
    this->y = valueY;

    array = new int*[x];
    for (int i = 0; i < x; ++i) {
        array[i] = new int[x];
    }

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            std::cout << "Enter number to " << i << " line, " << j << " Columns" << std::endl;
            std::cin >> array[i][j];
        }
    }
}

int* Array::getArray() {
    std::cout << "Array: [ \n";
    for (int i = 0; i < this->y; ++i) {
        for (int j = 0; j < this->x; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << " ]" << std::endl;

    if (x > 0 && y > 0) {
        return array[0];
    } else {
        return nullptr;
    }
}


