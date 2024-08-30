#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

class vector{
private:
	int * vect;
	int sz;

public:
	vector(int);
	~vector();

	int & operator [](int);
	int size();
	// void setSize(int valueSize);
};

#endif