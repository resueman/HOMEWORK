#include "list.h"
#include "readFromFile.h"
#include <iostream>

using namespace std;

bool test()
{
	List* originalList = readFromFile("file.txt");
	List* resultList = getResult(originalList);
	if (!check(resultList))
	{
		deleteList(originalList);
		deleteList(resultList);
		return false;
	}
	deleteList(originalList);
	deleteList(resultList);
	return true;
}

int main()
{
	/*if (!test())
	{
		cout << "Program doesn't work"
		return -1;
	}
	*/
	List* originalList = readFromFile("file.txt");
	List* resultList = getResult(originalList);

	printList(originalList);
	cout << "\n\n";
	printList(resultList);

	deleteList(originalList);
	deleteList(resultList);
	
	return 0;
}
