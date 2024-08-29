#include "../lib/Array.h"

Array::Array() {
    this->line = 0;
    this->column = 0;
    array = nullptr;
}

Array::~Array() {
    if (array != nullptr) {
        for (int i = 0; i < line; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }
}

void Array::setArray(int valueLine, int valueColumn) {
    this->line = valueLine;
    this->column = valueColumn;

    array = new int*[line];                // Створюється масив вказівників на масиви
    for (int i = 0; i < line; ++i) {
        array[i] = new int[column];          // Кожний вказівник отримує свій масив цілих чисел
    }

    for (int i = 0; i < line; ++i) {       // Проходження по всіх рядках
        for (int j = 0; j < column; ++j) {   // Проходження по всіх стовпцях
            // std::cout << "Enter number to " << i << " line, " << j << " Columns" << std::endl;
            // std::cin >> array[i][j];
            array[i][j] = j + 1;        // Ініціалізація елемента масиву
        }
    }
}


int* Array::getArray() {
    std::cout << "Array: [ \n";
    for (int i = 0; i < this->line; ++i) {
        for (int j = 0; j < this->column; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << " ]" << std::endl;

    if (line > 0 && line > 0) {
        return array[0];
    } else {
        return nullptr;
    }
}


