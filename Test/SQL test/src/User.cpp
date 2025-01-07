#include <iostream>
#include <string.h>
#include "../lib/User.h"

User::User(){
    this->id = 0;
    this->userName = "";
    this->userPassword = "";
}

User::~User(){}

    void User::setID(int valueID) {
        if (valueID > 0) {
            this->id = valueID;
        } else {
            std::cerr << "Invalid ID. It must be a positive integer.\n";
        }
    }

    void User::setUserName(std::string nameValue) {
        if (!nameValue.empty() && nameValue.length() <= 50) {
            this->userName = nameValue;
        } else {
            std::cerr << "Invalid user name. It must not be empty and should not exceed 50 characters.\n";
        }
    }

    void User::setUserPassword(std::string passwordValue) {
        if (!passwordValue.empty()) {
            this->userPassword = passwordValue;
        } else {
            std::cerr << "Invalid password. It must not be empty.\n";
        }
    }


int User::getID(){
    return id;
}
std::string User::getUserName(){
    return userName;
}
std::string User::getUserPassword(){
    return userPassword;
}

void User::installDB(std::string valueAnswer) {
    if (valueAnswer == "Y" || valueAnswer == "y") {
        std::cout << "Installing database...\n";

        std::string command = "chmod +x ../bash/installDB.sh";

        int result = system("sudo ../bash/installDB.sh");
        if (result == 0) {
            printf("Database installed successfully!\n");
        } else {
            printf("Error during database installation.\n");
        }
    } else {
        printf("Installation skipped.\n");
    }
}

void User::CreateUser(std::string valueAnswer) {
    if (valueAnswer == "Y" || valueAnswer == "y") {
        std::cout << "Enter user name: ";
        std::string name, password;
        std::getline(std::cin, name);
        setUserName(name);

        std::cout << "Enter user password: ";
        std::getline(std::cin, password);
        setUserPassword(password);

        std::string command = "../bash/CreateUser.sh " + getUserName() + " " + getUserPassword();

        int result = system(command.c_str());
        if (result == 0) {
            std::cout << "User created successfully!\n";
        } else {
            std::cerr << "Failed to create user.\n";
        }
    } else if (valueAnswer == "N" || valueAnswer == "n") {
        std::cout << "Exit!\n";
    } else {
        std::cerr << "Invalid input!\n";
    }
}
