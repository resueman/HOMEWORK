#include "readFromFile.h"
#include "merge.h"
#include "printToFile.h"
#include "test.h"

#include <iostream>

using namespace std;

int main()
{
	if (!test())
	{
		cout << "Not all tests passed ;(\n";
		return -1;
	}

	List* list1 = createList();
	List* list2 = createList();
	
	readFromFile("data1.txt", list1);
	readFromFile("data2.txt", list2);
	string answer = merge(list1, list2);
	printToFile("result.txt", answer);

	deleteList(list1);
	deleteList(list2);

	return 0;
}
