#include "../lib/Array.h"

Array::Array() {
    this->valueX = 0;
    this->valueY = 0;
    array = nullptr;  // Ініціалізуємо масив як nullptr
}

Array::~Array() {
    // Перевірка перед видаленням пам'яті
    if (array != nullptr) {
        for (int i = 0; i < valueX; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }
}

void Array::setArray(int valueX, int valueY) {
    // Оновлюємо розміри масиву
    this->valueX = valueX;
    this->valueY = valueY;

    // Виділяємо пам'ять для масиву
    array = new int*[valueX];
    for (int i = 0; i < valueX; ++i) {
        array[i] = new int[valueY];
    }

    // Заповнюємо масив значеннями
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

    // Перевірка перед поверненням
    if (valueX > 0 && valueY > 0) {
        return array[0];
    } else {
        return nullptr;
    }
}


