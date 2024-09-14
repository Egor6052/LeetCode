
#pragma once
#ifndef B_H
#define B_H

#include <iostream>
#include <string>
#include "A.h"

class B : public A {
public:
	std::string BName;

	B();
	~B();

};


#endif