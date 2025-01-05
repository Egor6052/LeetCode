#include <stdio.h>
#include <stdlib.h>
#include "../lib/User.h"

int main(){
    User user;
    printf("\033[35m Create DB! \033[0m\n ---- Instalation ----\n Y/N? ");

    char answer;
    answer = getchar();
    user.installDB(answer);

    printf("--- Create User ---\n Y/N?");
    answer = getchar();
    user.CreateUser(answer);

    //  const char *command = "echo 'This is a test command' && ls -l";

    // // Виконання команди
    // int result = system(command);

    return 0;
}