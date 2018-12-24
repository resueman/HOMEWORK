#include "list.h"
#include "test.h"
#include <locale>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	if (!test())
	{
		std::cout << "Everything is bad ;(";
		return -1;
	}
	std::cout << "Tests passed successfully!\n";
	Set* hashTable = createHashTable();
	readFromFile(hashTable, "file.txt");

	printHashTable(hashTable);
	std::cout << "Average list lenght:  " << averageListLength(hashTable) << "\n";
	std::cout << "Max list lenght:  " << maxListLength(hashTable) << "\n";
	std::cout << "Load factor:  " << loadFactor(hashTable) << "\n";
	
	deleteHashTable(hashTable);
	
	return 0;
}
