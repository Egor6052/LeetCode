#include <iostream>
#include <string>

using namespace std;

class Mans {

private: 
	int age;
	string name;
	int *array;

public: 

	Mans(int size) {
		this->array = new int[size];

		for(int i = 0; i < size; i++){
			array[i] = i+1;
		}

		cout << "Constructor: " << this << endl;
	}

	~Mans() {
		cout << "Distructor: " << this << endl;
		delete[] array;
	}

	void Print(int size){
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


	// void Function(Mans valueMan){
	// 	cout << "Function:" << endl;
	// }

	Mans Function2(){
		cout << "Function2:" << endl;
		int sizeArray = 10;
		Mans numberArray(sizeArray);
		numberArray.Print(sizeArray);

		return numberArray;
	}

int main(){

	// * указатель; 
	// & ссылка;

	// Mans man;
	// man.setAge(18);
	// man.setName("Andre");
	// man.Print();


	// Mans man2;
	// man2.setAge(20);
	// man2.setName("Kolya");
	// man2.Print();

	// Function(man2);

	Function2();

	return 0;
}
