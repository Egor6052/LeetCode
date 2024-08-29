#include "../lib/Days.h"
#include <iostream>

Days::Days(){
	this->allCalories = 0;
	this->counter = 0;
}

Days::~Days() {
    // std::vector автоматично звільнить пам'ять, тому нічого не потрібно робити
}

void Days::setArrayCalories(double newCalories) {
    arrayCalories.push_back(newCalories);
    allCalories += newCalories;
}

int Days::getSize() {
    return arrayCalories.size();
}

void Days::setCalories() {
    int value = 0;

    while (value == 0) {
        double calories = 0;

        std::cout << "Enter the calories: " << std::endl;
        std::cin >> calories;

        if (calories > 0) {
            counter++;
            setArrayCalories(calories);
            value = 0;
        } else {
            value = 1;
        }
    }
}

double Days::getAllCalories() const {
    return allCalories;
}
