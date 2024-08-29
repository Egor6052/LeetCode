#include "../lib/Table.h"

Table::Table(){
	this->column = 0;
	this->line = 0;
}
Table::~Table(){}

void Table::setColumn(int valueColumn){
	this->column = valueColumn;
}

void Table::setLine(int valueLine){
	this->line = valueLine;
}

int Table::getColumn(){
	return column;
}

int Table::getLine(){
	return line;
}

void Table::Print(){
	std::cout << "lines = " << line  << "; column = " << column << ";" << std::endl;
}