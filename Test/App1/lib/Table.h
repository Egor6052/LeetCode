#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>

class Table{
	private:
		int line, column;

	public:
	Table();
	~Table();

	void setLine(int valueLine);
	void setColumn(int valueColumn);

	int getLine();
	int getColumn();

	void Print();
};

#endif
