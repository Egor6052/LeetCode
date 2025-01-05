#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string.h>

class User {

private:
    int id;

public:
    User();
    ~User();

    void setID(int valueID);
    int getID();

    void installDB(char valueAnswer);
    void CreateUser(char valueAnswer);

};

#endif