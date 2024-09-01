#include <iostream>
#include <string>

using namespace std;

class Man {

private: 
	int age;
	string name;

public: 

	Man() {
		age = 0;
		cout << this << endl;
	}
	void Print(){
		cout << "Name: " << name << "\n" << "Ege: " << age << endl;
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

int main(){
	Man man;
	man.setAge(18);
	man.setName("Andre");
	man.Print();


	Man man2;
	man2.setAge(20);
	man2.setName("Kolya");
	man2.Print();

	return 0;
}
