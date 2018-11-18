#include "test.h"
#include "print.h"

using namespace std;

int readFromFile(Set *set)
{
	ifstream file;
	file.open("test.txt");
	if (!file.is_open())
	{
		cout << "File for test not found\n";
		return -1;
	}
	while (!file.eof())
	{
		int number = 0;
		file >> number;
		addToSet(set, number);
	}
	file.close();
	return 1;
}

bool test()
{
	std::string result1 = "";
	std::string result2 = "";
	std::string desiredResult1 = "-9 -7 -6 -5 -4 -3 0 1 2 5 6 7 8 ";
	std::string desiredResult2 = "8 7 6 5 2 1 0 -3 -4 -5 -6 -7 -9 ";
	
	Set *set = createSet();
	readFromFile(set);
	printAscendingOrder(set, set->root, result1);
	printDescendingOrder(set, set->root, result2);
	return result1 == desiredResult1 && result2 == desiredResult2;
}