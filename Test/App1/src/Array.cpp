#include "../lib/Array.h"

Array::Array() {
    this->valueX = 0;
    this->valueY = 0;
    array = nullptr;
}

Array::~Array() {
    if (array != nullptr) {
        for (int i = 0; i < valueX; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }
}

void Array::setArray(int valueX, int valueY) {
    this->valueX = valueX;
    this->valueY = valueY;

    array = new int*[valueX];
    for (int i = 0; i < valueX; ++i) {
        array[i] = new int[valueY];
    }

    for (int i = 0; i < valueX; ++i) {
        for (int j = 0; j < valueY; ++j) {
            array[i][j] = j + 1;
        }
    }
}

int* Array::getArray() {
    std::cout << "Array: [ \n";
    for (int i = 0; i < this->valueX; ++i) {
        for (int j = 0; j < this->valueY; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << " ]" << std::endl;

    if (valueX > 0 && valueY > 0) {
        return array[0];
    } else {
        return nullptr;
    }
}


