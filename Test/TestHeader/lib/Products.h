#pragma once
#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>
#include <string>


#include "FriendlyClass.h"
#include "Shop.h"

class FriendlyClass;
class Shop;

class Products {

    friend class Shop;
private:
    std::string name;
    int price;
    double weight;

    int size;
    int *data;
    static int count;

    int id;
public:
    int array[3]{1,2,3};
    Products();
    ~Products();

    void setName(std::string valueName);
    void setPrice(int valuePrice);
    void setWeight(double valueWeight);
    void setData(int newSize);
    // void setCount(int valueCount);

    std::string getName();
    int getPrice();
    double getWeight();
    int* getData();
    int getSize() const;
    static int getCount();
    int getID();

    void Print();

    void operator=(const Products &valueProduct);
    bool operator!=(const Products &valueProduct) const;
    bool operator==(const Products &valueProduct);
    Products operator+(const Products &valueProduct);
    Products & operator ++();
    Products operator ++(int valure);
    int & operator [](int index);

    friend void FriendlyFunction(Products &valueProduct);

    friend void FriendlyClass::SendMessage(Products &valueProduct);
    void Tovar(Products &valueTovar);

    static void changeNames(Products & product, std::string NewName);
};

// // Ініціалізація статіка;
// int Products::count = 0;
#endif // PRODUCTS_H