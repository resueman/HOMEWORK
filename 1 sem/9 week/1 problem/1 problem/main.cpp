#include "list.h"
#include "readFromFile.h"
#include "test.h"
#include <locale>
#include <iostream>

int main()
{
	if (!test())
	{
		std::cout << "Everything is bad ;(";
		return -1;
	}
	std::cout << "Tests passed successfully!";
	
	setlocale(LC_ALL, "Russian");
	Set* hashTable = createHashTable();
	readFromFile(hashTable, "file.txt");

	printHashTable(hashTable);
	std::cout << "Average list lenght:  " << averageListLength(hashTable) << "\n";
	std::cout << "Max list lenght:  " << maxListLength(hashTable) << "\n";
	std::cout << "Load factor:  " << loadFactor(hashTable) << "\n";
	
	deleteHashTable(hashTable);
	
	return 0;
}
