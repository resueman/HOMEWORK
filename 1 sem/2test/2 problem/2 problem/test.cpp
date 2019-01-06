#include "readFromFile.h"
#include "merge.h"
#include <iostream>

using namespace std;

bool test()
{
	//TEST 1
	List* listTest1 = createList();
	List* listTest2 = createList();

	readFromFile("dataTest1.1.txt", listTest1);
	readFromFile("dataTest2.1.txt", listTest2);
	string result1 = merge(listTest1, listTest2);
	string desiredResult1 = "0 1 2 3 3 4 5 5 10 11 12 15 27 30 50 60 70 80 90 ";
	if (result1 != desiredResult1)
	{
		deleteList(listTest1);
		deleteList(listTest2);
		cout << "test1 not passed\n";
		return false;
	}
	cout << "test 1 passed\n";
	
	deleteList(listTest1);
	deleteList(listTest2);

	//TEST 2
	List* listTest11 = createList();
	List* listTest22 = createList();

	readFromFile("dataTest1.2.txt", listTest11);
	readFromFile("dataTest2.2.txt", listTest22);
	string result2 = merge(listTest11, listTest22);
	string desiredResult2 = "1 3 5 6 7 8 9 ";
	if (result2 != desiredResult2)
	{
		deleteList(listTest11);
		deleteList(listTest22);
		cout << "test2 not passed\n";
		return false;
	}
	cout << "test 2 passed\n";

	deleteList(listTest11);
	deleteList(listTest22);

	cout << "All tests passed! ;)\n";
	return true;
}
