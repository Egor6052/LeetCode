#pragma once
#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>


class Human {
public:
	std::string name;
	int age;
	
	Human();
	~Human();
	void setName(std::string valueName);
	void setAge(int valueAge);

	std::string getName();
	int getAge();

	void Print();

};

#endif
