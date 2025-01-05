#include <iostream>
#include <string.h>
#include "../lib/User.h"

User::User(){
    this->id = 0;
}

User::~User(){}

void User::setID(int valueID){
    this->id = valueID;
}

int User::getID(){
    return id;
}

void User::installDB(char valueAnswer){


    if (valueAnswer == 'Y' || valueAnswer == 'y') {
        
        int result = system("../bash/installDB.sh");
        if (result == 0) {
            printf("Скрипт виконано успішно!\n");
        } else {
            printf("Помилка виконання скрипта.\n");
        }

    } else if (valueAnswer == 'N' || valueAnswer == 'n') {
        printf("Exit!\n");
    } else {
        printf("Invalid input!\n");
    }
}

void User::CreateUser(char valueAnswer){

    if (valueAnswer == 'Y' || valueAnswer == 'y') {
        // TODO
    const char *command = "echo 'Creating user...' && CREATE USER nameUser WITH PASSWORD 'userPasswoed';";
    int result = system(command);

    } else if (valueAnswer == 'N' || valueAnswer == 'n') {
        printf("Exit!\n");
    } else {
        printf("Invalid input!\n");
    }

}