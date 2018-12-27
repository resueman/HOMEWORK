#include "listFunctions.h"
#include "test.h"

std::string listToString(List* list)
{
	std::string result = "";
	auto current = getHead(list);
	while (current != nullptr)
	{
		result += std::to_string(getData(current)) + " ";
		current = getNext(current);
	}
	return result;
}

bool test()
{
	//TEST 1
	List* listTest1 = createList();
	addElement(listTest1, 3);
	addElement(listTest1, 5);
	addElement(listTest1, 7);
	addElement(listTest1, 4);
	addElement(listTest1, 1);
	addElement(listTest1, 9);
	addElement(listTest1, 0);
	addElement(listTest1, 6);
	addElement(listTest1, 1);
	addElement(listTest1, 0);
	addElement(listTest1, 8);
	addElement(listTest1, 9);
	addElement(listTest1, 9);
	addElement(listTest1, 6);

	std::string desiredResult = "0 0 1 1 3 4 5 6 6 7 8 9 9 9 ";
	std::string resultWeGot = listToString(listTest1);
	
	if (resultWeGot != desiredResult)
	{
		deleteList(listTest1);
		return false;
	}
	deleteList(listTest1);

	//Test 2
	List* listTest2 = createList();

	whatToDelete(listTest2, 1);
	addElement(listTest2, 1);
	whatToDelete(listTest2, 1);
	addElement(listTest2, 2);//
	whatToDelete(listTest2, 3);
	whatToDelete(listTest2, 1);
	addElement(listTest2, 1);//
	addElement(listTest2, 2);//
	addElement(listTest2, 3);//1 2 2 3
	whatToDelete(listTest2, 3);
	whatToDelete(listTest2, 2);
	whatToDelete(listTest2, 1);
	whatToDelete(listTest2, 2);//{o}
	addElement(listTest2, 0);//
	addElement(listTest2, 1);//
	addElement(listTest2, 7);//
	whatToDelete(listTest2, 1);

	desiredResult = "0 7 ";
	resultWeGot = listToString(listTest2);

	if (resultWeGot != desiredResult)
	{
		deleteList(listTest2);
		return false;
	}
	deleteList(listTest2);

	//Test 3
	List* listTest3 = createList();

	addElement(listTest3, 1);
	addElement(listTest3, 2);
	whatToDelete(listTest3, 2);
	whatToDelete(listTest3, 1);

	desiredResult = "";
	resultWeGot = listToString(listTest3);

	if (resultWeGot != desiredResult)
	{
		deleteList(listTest3);
		return false;
	}
	deleteList(listTest3);

	system("cls");

	return true;
}
