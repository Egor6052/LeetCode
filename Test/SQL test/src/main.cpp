#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/User.h"

int main(){
    User user;
    std::string answer;

    printf("\033[35m Create DB! \033[0m\n ---- Instalation ----\n Y/N? ");
    std::cin >> answer;
    std::cin.ignore();
    user.installDB(answer);

    printf("--- Create User ---\n Y/N?");
    std::cin >> answer;
    std::cin.ignore();
    user.CreateUser(answer);


    return 0;
}