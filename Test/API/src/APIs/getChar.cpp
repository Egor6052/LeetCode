#include <iostream>
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include <termios.h>
#include <unistd.h>
#include "../../lib/API.h"


char API::getChar() {
    struct termios oldt, newt;
    char ch;
    // Отримуємо поточні налаштування терміналу
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    // Вимикаємо буферизований ввід та відображення символів
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    // Зчитуємо символ
    ch = getchar();
    // Повертаємо налаштування назад
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}