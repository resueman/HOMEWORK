#include "list.h"
#include "test.h"
#include "mergeSort.h"
#include "readFromFile.h"

bool checkSort(List* list, bool byName)
{
	auto* current = getHead(list);

	if (byName) 
	{
		bool result = (*getName(current)).compare(*getName(getNext(current))) <= 0;
		while (getNext(current) != nullptr && result == true)
		{
			result = (*getName(current)).compare(*getName(getNext(current))) <= 0;
			current = getNext(current);
		}
		if (!result)
		{
			return false;
		}
	}
	else
	{
		bool result = (*getNumber(current)).compare(*getNumber(getNext(current))) <= 0;
		while (getNext(current) != nullptr && result)
		{
			result = (*getNumber(current)).compare(*getNumber(getNext(current))) <= 0;
			current = getNext(current);
		}
		if (!result)
		{
			return false;
		}
	}
	return true;
}

bool test()
{
	List *listTest1 = createList();
	readFromFile("test_1.txt", listTest1);

	//TEST 1
	mergeSortRecursive(listTest1, true);
	if (!(checkSort(listTest1, true)))
	{
		deleteList(listTest1);
		return false;
	}
	
	//TEST 2
	mergeSortRecursive(listTest1, false);
	if (!(checkSort(listTest1, false)))
	{
		deleteList(listTest1);
		return false;
	}
	deleteList(listTest1);

	List *listTest2 = createList();
	readFromFile("test_2.txt", listTest2);
	
	//TEST 3
	mergeSortRecursive(listTest2, true);
	if (!(checkSort(listTest2, true)))
	{
		deleteList(listTest2);
		return false;
	}
	
	//TEST 4
	mergeSortRecursive(listTest2, false);
	if (!(checkSort(listTest2, false)))
	{
		deleteList(listTest2);
		return false;
	}
	deleteList(listTest2);
	
	return true;
}
