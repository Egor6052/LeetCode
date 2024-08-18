#include <iostream>
#include <string>

using namespace std;

class Class {

public:

	// def convert_units(a, unit1, unit2):
    // m = [1000, 100, 1]
    // u1 = ["мм", "см", "м"]
    // return a / m[u1.index(unit1)] * m[u1.index(unit2)]

	double convert_units(double a, string unit1, string unit2) {
		int size = 3;

        int m[size] = {1000, 100, 1};

        string u1[size] = {"мм", "см", "м"};

        int index1 = 0;
        int index2 = 0;

        for (int i = 0; i < size; i++) {
            if (u1[i] == unit1) {
                index1 = i;
            }
            if (u1[i] == unit2) {
                index2 = i;
            }
        }

		// return 2 * 100 / 1;  // 2 см = 0.02 м
        return a / m[index1] * m[index2];
    }
};

int main(){

	Class object;
    int abc = 12;

	// print(convert_units)
	cout << object.convert_units(2, "см", "м") << endl;

	return 0;
}