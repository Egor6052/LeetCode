#include <iostream>
#include <string>
#include <random>

int main() {
    // Ініціалізація генератора випадкових чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 2);

    std::string array[3] = {
        "person1", 
        "person2", 
        "person3"
    };
    std:: string array1[3] = {
        "_1_", 
        "_2_", 
        "_3_"
    };

    // Виводимо 10 випадкових повідомлень
    for (int i = 0; i < 30; i++) {
        int random_number1 = dist(gen);
        std::cout << array[random_number1] << " + ";
        
        int random_number2 = dist(gen);
        std::cout << array[random_number2] << " = ";

        int random_number3 = dist(gen);
        std::cout << array1[random_number3] << "." << "\n-------------" << std::endl;

    }

    return 0;
}
    