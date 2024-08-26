#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>

class Table{
	private:
		int x, y;

	public:
	Table();
	~Table();

	void setX(int valueX);
	void setY(int valueY);

	int getx();
	int getY();

	void Print();
};

#endif
