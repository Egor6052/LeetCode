#include "../lib/Human.h"
#include <iostream>
#include <string>

Human::Human() {
    this->name = "NoName";
    this->age = 0;
}

Human::~Human() {
}

void Human::setName(std::string valueName){
	this->name = valueName;
}

void Human::setAge(int valueAge){
	this->age = valueAge;
}

std::string Human::getName(){
	return name;
}

int Human::getAge(){
	return age;
}

void Human::Print(){
	std::cout << "Name: " << name << "\n"<< "Age: " << age << std::endl;
}
