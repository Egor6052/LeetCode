#include "../lib/Table.h"
#include "../lib/Array.h"

int main()
{
	std::cout << "...Table app..." << std::endl;
	Table table;
	int line, column;
	std::cout << "Enter the array (lines, colums): \n line = " << std::endl;
	std::cin >> line;
	std::cout << "\ncolumn = " << std::endl;
	std::cin >> column;

	table.setLine(line);
	table.setColumn(column);

	table.Print();
	Array array1;
	array1.setArray(line, column);
	std::cout << "sixeof(int line) = " << sizeof(line) << std::endl;
	std::cout << "sixeof(int column) = " << sizeof(column) << std::endl;

	array1.getArray();
	return 0;
}