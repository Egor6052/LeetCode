#include <iostream>

using namespace std;

class Cursor {
private:
    int x;
    int y;

    int size;
    int *array;

public:
    // Constructor with parameters;
    Cursor(){
        x = 0;
        y = 0;
        size = 0;
        array = nullptr;
    }

    // Перегрузка конструктора; 
    Cursor(int valueX, int valueY, int valueSize){
        x = valueX;
        y = valueY;
        size = valueSize;
        array = nullptr;
    }

    // Диструктор;
    ~Cursor(){
    	delete [] array;
    }

    // Setters
    void setX(int positionX){
        x = positionX;
    }
    void setY(int positionY){
        y = positionY;
    }

    void setArray(int sizeArray){ 
    // звільняємо попередньо виділену пам'ять, якщо така є
    	delete[] array;
        size = sizeArray;
        array = new int[sizeArray];

 		if (array != nullptr) {
	    	for (int i = 0; i < sizeArray; i++){
	    		array[i] = i;
	    	}
    	} else {
            cout << "Array не ініціалізовано." << endl;
        }
    }

    // Getters
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int* getArray(){
    	return array;
    }

    void Print(){
        cout << "X = " << x << "\nY = " << y << "\n" << endl;
            cout << "array[";
        for (int i = 0; i < size; i++){
        	cout << " " << array[i] << " ";
    	}
            cout << "];" << endl;

    }
};

int main(){
	setlocale(LC_ALL, "ru");
	setlocale(LC_ALL, "ua");

    Cursor cursor;
    cursor.Print();

    Cursor array1;
    array1.setArray(10);

    array1.Print();

    return 0;
}
