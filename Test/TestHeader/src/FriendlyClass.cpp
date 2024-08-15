#include <iostream>
#include "../lib/FriendlyClass.h"
#include "../lib/Products.h"

void FriendlyClass::SendMessage(Products &valueProduct) {
    std::cout << "Send message..." << valueProduct.name << std::endl;
}