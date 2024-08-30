#include "../lib/Vector.h"

int main(){

	vector v1(10);
	std::cout << "Size: " << v1.size() << std::endl;

	for (int n = 0; n < v1.size(); n++){
		v1[n] = n + 1;
		std::cout << "Number: " << n << "; Element: " << v1[n] << ";" << std::endl; 
	}

	return 0;
};
