#pragma once
#include <iostream>
#include <string>

class Products {
private:
    std::string name;  // Використовуємо std::string
    int price;
    double weight;

    int size;
    int *data;

public:
    Products();
    ~Products();

    void setName(std::string valueName);  // Використовуємо std::string
    void setPrice(int valuePrice);
    void setWeight(double valueWeight);
    void setData(int newSize);

    std::string getName();  // Використовуємо std::string
    int getPrice();
    double getWeight();
    int* getData();
    int getSize() const;

    void Print();

    void operator=(const Products &valueProduct);
    bool operator!=(const Products &valueProduct) const;
    bool operator==(const Products &valueProduct);
};
