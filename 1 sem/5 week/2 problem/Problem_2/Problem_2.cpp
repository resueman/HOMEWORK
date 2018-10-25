#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct Element
{
	int data = 0;
	Element* next = nullptr;
	Element* prev = nullptr;
};

struct List
{
	Element* head = nullptr;
	Element* tail = nullptr;
	Element* toKill = nullptr;
}list;

void addToList(int nuberOfWarriors, List &list)
{
	struct Element* elemToAddPrev = new Element{ 1, nullptr, nullptr };
	list.head = elemToAddPrev;
	list.tail = elemToAddPrev;
	for (int i = 2; i < nuberOfWarriors + 1; ++i)
	{
		auto elemToAddCurr = new Element{ i, list.head, nullptr };
		elemToAddPrev->next = elemToAddCurr;
		elemToAddCurr->prev = elemToAddPrev;
		list.tail = elemToAddCurr;
		elemToAddPrev = elemToAddCurr;
	}
	list.head->prev = list.tail;
}

int whoSurvive(int victimNumber)
{
	list.toKill = list.head;
	while (list.head != list.tail)
	{
		for (int i = 1; i < victimNumber; ++i)
		{
			list.toKill = list.toKill->next;
		}
		if (list.toKill == list.head) 
		{
			list.head = list.head->next;
		}
		if (list.toKill == list.tail) 
		{
			list.tail = list.tail->prev;
		}
		(list.toKill->prev)->next = list.toKill->next;
		(list.toKill->next)->prev = list.toKill->prev;
		Element *temp = list.toKill;
		list.toKill = list.toKill->next;
		delete temp;
	}
	int const survivorNumber = list.tail->data;
	delete list.tail;
	list.head = nullptr;
	list.tail = nullptr;
	return survivorNumber;
}

int testFunc(int numberOfWarriors, int victimNumber)
{
	addToList(numberOfWarriors, list);
	return whoSurvive(victimNumber);
}

bool test()
{
	return (testFunc(1,1) == 1 && testFunc(3, 1) == 3 && testFunc(3, 3) == 2 && testFunc(3, 2) == 3 && 
		testFunc(4, 2) == 1 && testFunc(1, 5) == 1 && testFunc(5, 7) == 4 && testFunc(10, 2) == 5 &&
		testFunc(7, 2) == 7 && testFunc(2, 2) == 1 && testFunc(2, 3) == 2);
}

int main()
{
	if (!test())
	{
		printf("Program doesn't work :(");
		return -1;
	}
	else
	{
		int numberOfWarriors = 0;
		int victimNumber = 0;

		printf("Enter the number of warriors:   ");
		scanf("%d", &numberOfWarriors);
		printf("Enter the number of victim:   ");
		scanf("%d", &victimNumber);

		addToList(numberOfWarriors, list);
		printf("Number of survivivor:   %d", whoSurvive(victimNumber));
	}
	return 0;
}
