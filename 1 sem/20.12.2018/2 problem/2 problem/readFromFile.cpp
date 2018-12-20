#include "readFromFile.h"
#include "list.h"
#include <fstream>
#include <istream>
#include <iostream>
#include <string>

using namespace std;

List* readFromFile(const char* fileName)
{
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		std::cout << "File isn't opened\n";
		return nullptr;
	}

	List* list = createList();
	
	while (!file.eof())
	{
		string inputStr;
		file >> inputStr;
		add(list, inputStr);
	}
	file.close();
	
	return list;
}