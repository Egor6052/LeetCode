#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <string>

class Days {
private:
    // std::string name;
    std::vector<double> arrayCalories; // Векторний масив всіх калорій
    double allCalories;
    int counter;  // лічильник

public:
    Days();
    ~Days();

    void setArrayCalories(double newCalories);
    int getSize();
    void setCalories();
    double getAllCalories() const;
};

#endif
