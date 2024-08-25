#include "../lib/Human.h"

int main(){
	std::cout << "...Start Inheritance..." << std::endl;

	Human human1;
	human1.setName("Ivan");
	human1.setAge(25);
	human1.Print();

	return 0;
}