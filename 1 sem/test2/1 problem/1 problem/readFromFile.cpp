#include "readFromFile.h"
#include "list.h"
#include <fstream>
#include <istream>
#include <iostream>

bool read(List* list, const char* fileName)
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
		int number = 0;
		file >> number;
		add(list, number);
	}
	file.close();
	return true;
}