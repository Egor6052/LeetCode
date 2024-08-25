#include "../lib/Students.h"
#include <iostream>
#include <string>

Students::Students(){
	this->Course = "NoCourse";
	this->points = 0;
}

Students::~Students(){

}

void Students::setCourse(std::string value){
	this->Course = value;
}
void Students::setPoints(double valuePoints){
	this->points = valuePoints;
}

std::string Students::getCourse(){
	return Course;
}

double Students::getPoints(){
	return points;
}

void Students::Print(){
	Human::Print();
	std::cout << "University Course: " << Course << "\n" << "Points: " << points << std::endl;
}