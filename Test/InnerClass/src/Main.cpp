#include "../lib/Image.h"

int main() {
    Image icon;
    icon.setImg("Img1");
    icon.setWidth(2060);
    icon.setHeight(1280);
    icon.Print();
    icon.getPixelInfo();
	std::cout << "\n" << std::endl;
    
    Image::pixels[0] = Image::Pixel(11, 123, 345);

    icon.getPixelInfo();

    // std::cout << "Element 0:" << Image::pixels[0].Print() << std::endl;

    return 0;
}
