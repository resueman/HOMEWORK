#include "readFromFile.h"
#include <fstream>
#include <istream>
#include <iostream>

bool readFromFile(const char* fileName, List* list)
{
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		std::cout << "File isn't opened\n";
		return false;
	}
	int size = 0;
	file >> size;
	for (int i = 0; i < size; ++i)
	{
		int number = 0;
		file >> number;
		add(list, number);
	}
	file.close();
	return true;
}
