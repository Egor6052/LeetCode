#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include "../lib/Table.h"

class Array : public Table {
	private: 
	    int** array;
	    int valueX;
	    int valueY;
	public:
		Array();
		~Array();
		void setArray(int valueX, int valueY);

		int* getArray();
};

#endif
