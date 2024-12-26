#ifndef STUDENTS2_H
#define STUDENTS2_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Students2 {
private:
    std::string name;
    float mtiu, os, ppsu, avp1, ptc1, avp2, ptc2, ppm, oop, cm;
    float reyting;

public:
    // Конструктор
    Students2(std::string name, float mtiu, float os, float ppsu, float avp1,
              float ptc1, float avp2, float ptc2, float ppm, float oop, float cm);

    // Деструктор
    ~Students2() = default;

    // Методи
    void calculateRating();
    float getRating() const;
    std::string getName() const;

    // Статичний метод
    static void sortAndDisplay(std::vector<Students2>& students);
};

#endif // STUDENTS2_H
