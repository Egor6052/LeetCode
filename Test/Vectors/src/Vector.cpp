#include "../lib/Vector.h"

vector::vector(int valueSize){
	if (valueSize <= 0){
		throw std::out_of_range("Bad vector size!");
	} else {
		sz = valueSize;
		vect = new int[sz];
	}
}

vector::~vector(){
	delete vect;
}

int vector::size(){
	return sz;
}


int& vector::operator [](int i){
	if (i < 0 || sz <= i){
		throw std::out_of_range("Index out of range");
	} else {
		return vect[i];
	}
}

// void vector::setSize(int valueSize){
// 	if (valueSize <= 0){
// 		error("Bad size!");
// 	} else {
// 		size = valueSize;
// 	}
// }
