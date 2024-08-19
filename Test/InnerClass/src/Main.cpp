#include "../lib/Image.h"	

int main(){
	Image icon;
	icon.setImg("Img1");
	icon.setWidth(2060);
	icon.setHeight(1280);
	icon.Print();
	icon.getPixelInfo();
	return 0;
};