#include "../lib/Image.h"

int main() {
    Image icon;
    icon.setImg("Img1");
    icon.setWidth(2060);
    icon.setHeight(1280);
    icon.Print();
    icon.getPixelInfo();
    std::cout << "\n" << std::endl;

    // Використовуємо публічний метод для встановлення значення пікселя
    icon.setPixel(0, 11, 123, 345);

    icon.getPixelInfo();

    return 0;
}
