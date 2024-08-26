#pragma once
#ifndef ARRAY_H
#define ARRAY_H

class Array : public Table {
	private: 
		int * array;
	public:
		Array();
		~Array();
		void setArray(int valueX, int valueY);

		int* getData();
};

#endif
