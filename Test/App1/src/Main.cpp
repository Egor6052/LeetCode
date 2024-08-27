#include "../lib/Table.h"
#include "../lib/Array.h"

int main()
{
	std::cout << "...Table app..." << std::endl;
	Table table;
	int x = 10;
	int y = 10;

	table.setX(x);
	table.setY(y);

	table.Print();
	Array array1;
	array1.setArray(x, y);

	array1.getArray();
	return 0;
}