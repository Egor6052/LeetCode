
#include "../lib/C.h"

#include <iostream>
#include <string>

C::C(){
	this->CName = "I`m class C";
	std::cout << CName << std::endl;
}

C::~C(){}