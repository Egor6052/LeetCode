#include <iostream>
#include <string>

using namespace std;

class Mans {

private: 
	int age;
	string name;
	int *array;
	int size = 10;

public: 

	Mans() {
		this->array = new int[size];
		age = 0;
		name = "NoName";
		for(int i = 0; i < size; i++){
			array[i] = i+1;
		}

		cout << "Constructor! " << this << endl;
	}

	~Mans() {
		cout << "Distructor! " << this << endl;
		delete[] array;
	}

	void Print(){
		cout << "Name: " << name << "\n" << "Ege: " << age << endl;

		for (int i = 0; i < size; i++){
			cout << array[i] << " ";
		}
		cout << "\n";
	}

	void setAge(int valueAge){
		if (valueAge < 0) {
			cout << "Age is < 0!" << endl;
		} else {
			age = valueAge;
		}
		
	}

	void setName(string valueName){
		if (valueName == "" && valueName == " "){
			cout << "Name is __ !" << endl;
		} else {
			name = valueName;
		}
	}

	int getAge(){
		return age;
	}

	string getName(){
		return name;
	}

};


	void Function(Mans valueMan){
		cout << "Function1:" << endl;
		valueMan.Print();
	}

	// Copy constructor;
	Mans Function2(){
		cout << "Function2:" << endl;
		Mans temp;
		temp.Print();

		return temp;
	}

int main(){

	// * указатель; 
	// & ссылка;

	// Mans man;
	// man.setAge(18);
	// man.setName("Andre");
	// man.Print();


	// Mans man1;
	// man1.setAge(20);
	// man1.setName("Kolya");
	// man1.Print();

	// Function(man1);
	Function2();


	return 0;
}
