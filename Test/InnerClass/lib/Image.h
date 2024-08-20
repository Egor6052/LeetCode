#pragma once
#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>

class Image {
private:
    std::string img;
    int width;
    int height;
    static int count;
    int id;
    static constexpr int size = 5; // Використання constexpr для розміру масиву

public:
    void getPixelInfo();

    // Внутрішній клас Pixel
    class Pixel {
    private:
        int r, g, b;

    public:
        Pixel();
        Pixel(int r, int g, int b);
        std::string Print();
    };

    static Pixel pixels[size]; // Оголошення масиву статичних об'єктів класу Pixel

    Image();
    ~Image();

    void setImg(std::string valueImg);
    void setWidth(int valueWidth);
    void setHeight(int valueHeight);

    std::string getImg();
    int getWidth();

    static int getCount();
    int getID();

    void Print();
};

#endif
