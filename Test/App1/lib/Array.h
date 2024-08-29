#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include "../lib/Table.h"

class Array : public Table {
	private: 
	    int** array;
	    int line;
	    int column;

	public:
		Array();
		~Array();
		void setArray(int valueLine, int valueColumn);

		int* getArray();
};

#endif
