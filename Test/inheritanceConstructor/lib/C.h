
#pragma once
#ifndef C_H
#define C_H

#include <iostream>
#include <string>
#include "B.h"

class C : public B {
public:
	std::string CName;

	C();
	~C();

};


#endif