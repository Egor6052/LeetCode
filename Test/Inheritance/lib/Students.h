#pragma once
#ifndef STUDENTS_H
#define STUDENTS_H

#include "Human.h"
#include <iostream>
#include <string>

class Students : public Human {

public:
	std::string Course;
	double points;

	Students();
	~Students();
	void setCourse(std::string value);
	void setPoints(double valuePoints);

	std::string getCourse();
	double getPoints();

	void Print();

};

#endif
