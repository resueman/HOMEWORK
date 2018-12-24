#include "list.h"
#include <fstream>
#include <istream>
#include <iostream>

using namespace std;

bool readFromFile(const char* fileName, List* list)
{
	ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "File isn't opened\n";
		return false;
	}
	while (!file.eof())
	{
		string name = "";
		string number = "";
		file >> name >> number;
		copyToList(list, name, number);
	}
	file.close();
	return true;
}
