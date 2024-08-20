#include "../lib/Image.h"	
#include <iostream>
#include <string>

int Image::count = 0;
Image::Pixel Image::pixels[size];

Image::Image() {
    img = "NoName";
    width = 0;
    height = 0;
    count++;
    id = count;

    // Ініціалізація масиву пікселів
    for (int i = 0; i < size; ++i) {
        pixels[i] = Pixel(0, 0, 0);
    }
}

Image::~Image() {
    // delete[] pixels;
}


void Image::setImg(std::string valueImg){
	this->img = valueImg;
}
void Image::setWidth(int valueWidth){
	this->width = valueWidth;
}
void Image::setHeight(int valueHeight){
	this->height = valueHeight;
}


std::string Image::getImg(){
	return img;
}

int Image::getWidth(){
	return width;
}

int Image::getCount(){
	return count;
}

int Image::getID(){
	return id;
}

void Image::Print(){
	std::cout << "Name: " << img << "\nWidth: " << width << "\nHeight: " << height << std::endl;
}




// Внутрішній клас Pixel;

Image::Pixel::Pixel(int r, int g, int b){
	this->r = r;
	this->g = g;
	this->b = b;
}

Image::Pixel::Pixel(){
	r = g = b = 0;
}


std::string Image::Pixel::Print() {
    return "Pixel RGB: (R = " + std::to_string(r) + ", G = " + std::to_string(g) + ", B = " + std::to_string(b) + ")";
}


void Image::getPixelInfo() {
    for (int i = 0; i < Image::size; i++) {
        std::cout << Image::pixels[i].Print() << std::endl;
    }
}
