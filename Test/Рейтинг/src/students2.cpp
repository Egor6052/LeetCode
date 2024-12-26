#include "../lib/students2.h"

// Конструктор
Students2::Students2(std::string name, float mtiu, float os, float ppsu, float avp1,
                     float ptc1, float avp2, float ptc2, float ppm, float oop, float cm)
    : name(name), mtiu(mtiu), os(os), ppsu(ppsu), avp1(avp1), ptc1(ptc1),
      avp2(avp2), ptc2(ptc2), ppm(ppm), oop(oop), cm(cm), reyting(0.0f) {}

// Обчислення рейтингу
void Students2::calculateRating() {
    reyting = (mtiu + os + ppsu + avp1 + ptc1 + avp2 + ptc2 + ppm + oop + cm) / 10.0f;
}

// Отримання рейтингу
float Students2::getRating() const {
    return reyting;
}

// Отримання імені
std::string Students2::getName() const {
    return name;
}

// Сортування та вивід
void Students2::sortAndDisplay(std::vector<Students2>& students) {
    std::sort(students.begin(), students.end(),
              [](const Students2& a, const Students2& b) {
                  return a.getRating() > b.getRating();
              });

    for (const auto& student : students) {
        std::cout << "Name: " << student.getName() 
                  << ", Rating: " << student.getRating() << std::endl;
    }
}
