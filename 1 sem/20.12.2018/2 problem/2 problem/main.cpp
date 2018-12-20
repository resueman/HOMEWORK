#include "list.h"
#include "readFromFile.h"
#include <iostream>

using namespace std;

bool test()
{
	List* originalList = readFromFile("test.txt");
	List* resultList = getResult(originalList);
	if (printList(resultList) == "a b c d e ") 
	{
		deleteList(originalList);
		deleteList(resultList);
		return true;
	}
	deleteList(originalList);
	deleteList(resultList);
	return false;
}

int main()
{
	if (!test())
	{
		cout << "Program doesn't work";
		return -1;
	}
	
	List* originalList = readFromFile("file.txt");
	List* resultList = getResult(originalList);

    cout <<	printList(originalList);
	cout << "\n\n";
	cout << printList(resultList);

	deleteList(originalList);
	deleteList(resultList);
	
	return 0;
}
