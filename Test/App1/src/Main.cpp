#include "../lib/Table.h"
#include "../lib/Array.h"

int main()
{
	std::cout << "...Table app..." << std::endl;
	Table table;
	int x, y;
	std::cout << "Enter the array (x, y): \n x = " << std::endl;
	std::cin >> x;
	std::cout << "\ny = " << std::endl;
	std::cin >> y;

	table.setX(x);
	table.setY(y);

	table.Print();
	Array array1;
	array1.setArray(x, y);

	array1.getArray();
	return 0;
}