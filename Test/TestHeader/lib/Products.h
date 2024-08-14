#pragma once
// #ifndef 
#include <iostream>
#include <string>

class Products {
private:
    std::string name;
    int price;
    double weight;

    int size;
    int *data;

public:
    int array[3]{1,2,3};
    Products();
    ~Products();

    void setName(std::string valueName);
    void setPrice(int valuePrice);
    void setWeight(double valueWeight);
    void setData(int newSize);

    std::string getName();
    int getPrice();
    double getWeight();
    int* getData();
    int getSize() const;

    void Print();

    void operator=(const Products &valueProduct);
    bool operator!=(const Products &valueProduct) const;
    bool operator==(const Products &valueProduct);
    Products operator+(const Products &valueProduct);
    Products & operator ++();
    Products operator ++(int valure);
    int & operator [](int index);

    friend void FriendlyFunction(Products &valueProduct);
};
