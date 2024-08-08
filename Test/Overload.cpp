#include <iostream>
#include <string.h>
using namespace std;

class Products{
private:
	string name;
	int price;
	double weight;

	int size;
	int *data;
public:
	// Constructor;
	Products(){
		name = "NoName";
		price = 0;
		weight = 0;

		size = 0;
		data = nullptr;

	}
	// Distructor; 
	~Products(){
		cout << "Distructor: " << this << endl;
		delete [] data;
	}
	
	void setName(string valueName){
		if (!valueName.empty()){
			name = valueName;
		} else {
			cout << "Name is null. But now = NoName." << endl;
			name = "NoName";
		}
		
	}
	void setPrice(int valuePrice){
		price = valuePrice;
	}
	void setWeight(double valueWeight){
		weight = valueWeight / 1000;
	}
	void setData(int newSize) {
        if (newSize > 0) {
        	// Звільняємо старий масив
            delete[] data;

            data = new int[newSize];
            size = newSize;
            for (int i = 0; i < size; ++i) {
                data[i] = i + 1;
            }
        } else {
            size = 0;
            data = nullptr;
        }
    }

    

	string getName(){
		return name;
	}
	int getPrice(){
		return price;
	}
	double getWeight(){
		return weight;
	}
	int* getData() {
        return data;
    }

    int getSize() const {
        return size;
    }


	void Print(){
		cout << this << endl;
		cout << "Name: " << name << "\n" << "Price: " << price << " грн" << "\n" << "Weight: " << weight << " Кг" << "\n" << endl;

		cout << "Data [ ";
		for (int i = 0; i < size; i++){
			cout << data[i] << " " ;
		}
		cout << "];" << endl;
	}

	// Peregruzka =;
	void operator = (const Products &valueProduct){
		cout << "Operator '='" << endl;
		this->size = valueProduct.size;

		// Якщо данні у новому масиві є;
		if (this->data != nullptr){
			delete [] this->data;
		}

		this->data = new int[valueProduct.size];
		for(int i = 0; i < valueProduct.size; i++){
			this->data[i] = valueProduct.data[i];
	
		}

		this->name = valueProduct.name;
		this->price = valueProduct.price;
		this->weight = valueProduct.weight;

	}

	// Overload !=
	bool operator != (const Products &valueProduct) const {
	    if (this->name != valueProduct.name ||
	        this->price != valueProduct.price ||
	        this->weight != valueProduct.weight ||
	        this->size != valueProduct.size) {
	        return true;
	    }

	    // Якщо основні атрибути рівні, перевіряємо дані
	    for (int i = 0; i < this->size; i++) {
	        int valueI = this->data[i];

	        // Перевіряємо, чи дані рівні
	        if (valueI != valueProduct.data[i]) {
	            return true;
	        }
	    }

	    // Якщо всі перевірки не виявили відмінностей, об'єкти рівні
	    return false;
	}

	// Overload == ;
	bool operator == (const Products &valueProduct){

		if (this->name == valueProduct.name &&
		 	this->price == valueProduct.price &&
		  	this->weight == valueProduct.weight &&
		  	this->size == valueProduct.size){

			int comparison = 0;

			for (int i = 0; i < this->size; i++){
				int valueI = this->data[i];

				for (int j = 0; j < valueProduct.size; j++){
					int valueJ = valueProduct.data[i];

					if (valueI == valueJ){
						comparison += 1;
					} else {
						comparison -= 1;
					}
				}
			}
			// Якщо все співпало, то дорівнює;
			return comparison == this->size && comparison == valueProduct.size;
		}
		else {
			return false;
		}
	}
};

int main(){

	Products banana;
	banana.setName("Banana");
	banana.setPrice(90);
	banana.setWeight(1500);
	banana.setData(10);
	banana.Print();

	Products persik;
	// persik = banana;
	persik.setName("Persik");
	persik.setPrice(50);
	persik.setData(20);
	
	// bool result = persik == banana;
	bool result = persik != banana;
	if (result){
		cout << "!=" << endl;
	}


	persik.Print();
	return 0;
}