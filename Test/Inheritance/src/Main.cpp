#include "../lib/Human.h"
#include "../lib/Students.h"

int main(){
	std::cout << "...Start Inheritance..." << std::endl;

	// Human human1;
	// human1.setName("Ivan");
	// human1.setAge(25);
	// human1.Print();

	Students student1;
	student1.setName("Ivan");
	student1.setAge(25);
	student1.setCourse("Electronicks");
	student1.setPoints(100);
	student1.Print();

	return 0;
}