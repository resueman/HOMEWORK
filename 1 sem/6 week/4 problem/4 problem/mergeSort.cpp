#include "list.h"
#include "mergeSort.h"

void splitList(List* list, List *&leftList, List *&rightList)
{
	leftList = createList();
	rightList = createList();

	auto* current = getHead(list);

	for (int i = 0; i < listLenght(list) / 2; ++i)
	{
		copyToList(leftList, getName(current), getNumber(current));
		current = getNext(current);
	}
	for (int i = listLenght(list) / 2; i < listLenght(list); ++i)
	{
		copyToList(rightList, getName(current), getNumber(current));
		current = getNext(current);
	}
}

void merge(List *&list, List *&leftList, List *&rightList, const bool byName)
{
	auto* tempLeft = getHead(leftList);
	auto* tempRight = getHead(rightList);
	auto* tempResult = getHead(list);

	while (tempLeft != nullptr && tempRight != nullptr)
	{
		bool result = true;
		if (byName)
		{
			result = (getName(tempLeft)).compare(getName(tempRight)) < 0;
		}
		else
		{
			result = (getNumber(tempLeft)).compare(getNumber(tempRight)) < 0;
		}

		if (result)
		{
			copyElement(tempResult, tempLeft);
			tempLeft = getNext(tempLeft);
		}
		else
		{
			copyElement(tempResult, tempRight);
			tempRight = getNext(tempRight);
		}
		tempResult = getNext(tempResult);
	}
	while (tempLeft != nullptr)
	{
		copyElement(tempResult, tempLeft);
		tempResult = getNext(tempResult);
		tempLeft = getNext(tempLeft);
	}
	while (tempRight != nullptr)
	{
		copyElement(tempResult,tempRight);
		tempResult = getNext(tempResult);
		tempRight = getNext(tempRight);
	}
}

void mergeSortRecursive(List* list, const bool byName)
{
	if (listLenght(list) == 1)
	{
		return;
	}

	List* leftList = nullptr;
	List* rightList = nullptr;
	 
	splitList(list, leftList, rightList);
	
	mergeSortRecursive(leftList, byName);
	mergeSortRecursive(rightList, byName);
	merge(list, leftList, rightList, byName);

	deleteList(leftList);
	deleteList(rightList);
}
