#include "list.h"
#include "hashTable.h"
#include "test.h"
#include <fstream>
#include <locale>
#include <istream>
#include <iostream>
#include <conio.h>
using namespace std;

bool readFromFile(Set* hashTable, const char* fileName)
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
		string word = "";
		file >> word;
		addToHashTable(hashTable, word);
	}
	file.close();
	return true;
}

int main()
{
	/*
	if (!test())
	{
		std::cout << "Everything is bad ;(";
		return -1;
	}
	std::cout << "Tests passed successfully!";
	*/
	setlocale(LC_ALL, "Russian");
	Set* hashTable = createHashTable();
	readFromFile(hashTable, "file.txt");
	printHashTable(hashTable);
	_getch();
	return 0;
}
