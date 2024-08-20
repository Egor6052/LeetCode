#include "../lib/Image.h"

int main() {
    Image icon;
    icon.setImg("Img1");
    icon.setWidth(2060);
    icon.setHeight(1280);
    icon.Print();
    icon.getPixelInfo();  // Викликає метод getPixelInfo() для об'єкта Image

    // const int size = 4;

    // Image::Pixel array[size] = {
    //     Image::Pixel(100, 150, 200),
    //     Image::Pixel(120, 160, 210),
    //     Image::Pixel(140, 170, 220),
    //     Image::Pixel(160, 180, 230)
    // };

    // std::cout << "Element 0:" << array[0].Print() << std::endl;

    return 0;
}
