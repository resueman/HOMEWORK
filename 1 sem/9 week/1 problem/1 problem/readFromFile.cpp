#include "readFromFile.h"
#include <fstream>
#include <istream>
#include <iostream>

bool readFromFile(Set* hashTable, const char* fileName)
{
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		std::cout << "File isn't opened\n";
		return false;
	}
	while (!file.eof())
	{
		std::string word = "";
		file >> word;
		addToHashTable(hashTable, word);
	}
	file.close();
	return true;
}
