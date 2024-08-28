#include "../lib/Table.h"

Table::Table(){
	this->x = 0;
	this->y = 0;
}
Table::~Table(){}

void Table::setX(int valueX){
	this->x = valueX;
}

void Table::setY(int valueY){
	this->y = valueY;
}

int Table::getx(){
	return x;
}

int Table::getY(){
	return y;
}

void Table::Print(){
	std::cout << "Columns = " << x  << "; lines = " << y << ";" << std::endl;
}