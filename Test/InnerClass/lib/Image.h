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

    static const int size = 5;

    // Внутрішній клас Pixel
    class Pixel {
    private:
        int r, g, b;
    public:
        Pixel();
        Pixel(int r, int g, int b);
        std::string Print();

        void Output();

        // Друзі класу Pixel для доступу до приватних членів
        friend class Image;
    };

    static Pixel pixels[size];

public:

    Pixel pixel;

    void Output();
    void getPixelInfo();
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

    // Публічні методи для роботи з пікселями
    static void setPixel(int index, int r, int g, int b);
    static Pixel getPixel(int index);
};

#endif
