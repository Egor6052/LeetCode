#include "../lib/Array.h"

Array::Array(){
	data = nullptr;
}

Array::~Array(){
	delete[] data;
}

void Array::setArray(int valueX, int valueY){
    if (valueX > 0 && valueY > 0) {
        delete[] data;
        data = new int[valueX][valueY];
        for (int i = 0; i < valueX; ++i) {
        	for (int j = 0; j < valueY; ++j){
 				data[i][j] = j + 1;
        	}
        }
    } else {
        data = nullptr;
    }
}

