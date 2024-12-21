#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

class Function {
private:
	int width = 40; // ширина графіка
	int height = 20; // висота графіка
public:
	Function();
	~Function();
	void drow(int width, int height);
	// void Print();
};

#endif