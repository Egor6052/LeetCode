#include "../lib/Table.h"

int main()
{
	std::cout << "...Table app..." << std::endl;
	Table table;
	int x = 10;
	int y = 10;

	table.setX(x);
	table.setY(y);

	table.Print();

	return 0;
}