#include <iostream>
#include <string>
#include "../lib/Days.h"

int main() {
    Days day;

    day.setCalories();

    std::cout << "Total calories: " << day.getAllCalories() << std::endl;
    std::cout << "Number of entries: " << day.getSize() << std::endl;

    return 0;
}
