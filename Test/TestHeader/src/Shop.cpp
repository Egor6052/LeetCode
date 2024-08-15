#include "../lib/Shop.h"
#include "../lib/Products.h"
#include <iostream>

void Shop::Tovar(Products &valueTovar){
	std::cout << "Shop: " << valueTovar.name << std::endl;
}