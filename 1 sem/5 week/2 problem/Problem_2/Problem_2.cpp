#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct Element
{
	int data = 0;
	Element* next = nullptr;
};

struct List
{
	Element* head = nullptr;
	Element* toKill = nullptr;
};

void addToList(int nuberOfWarriors, List &list)
{
	auto elemToAdd = new Element{ 1, nullptr };
	list.head = elemToAdd;
	for (int i = 2; i < nuberOfWarriors + 1; ++i)
	{
		auto elemToAddCurr = new Element{ i,  nullptr };
		elemToAdd->next = elemToAddCurr;
		elemToAdd = elemToAddCurr;
	}
	elemToAdd->next = list.head;
}

Element* pointerOnPrevious(List &list, Element* current)
{
	Element* previous = list.head;
	while (previous->next != current)
	{
		previous = previous->next;
	}
	return previous;
}

int whoSurvive(int victimNumber, List list)
{
	list.toKill = list.head;
	while (list.head->next != list.head)
	{
		for (int i = 1; i < victimNumber; ++i)
		{
			list.toKill = list.toKill->next;
		}
		if (list.toKill == list.head) 
		{
			list.head = list.head->next;
		}
		pointerOnPrevious(list, list.toKill)->next = list.toKill->next;
		Element *temp = list.toKill;
		list.toKill = list.toKill->next;
		delete temp;
	}
	int const survivorNumber = list.head->data;
	delete list.head;
	list.head = nullptr;
	return survivorNumber;
}

int testFunc(int numberOfWarriors, int victimNumber)
{
	List listTest;
	addToList(numberOfWarriors, listTest);
	return whoSurvive(victimNumber, listTest);
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
		
		List list;
		addToList(numberOfWarriors, list);
		printf("Number of survivivor:   %d", whoSurvive(victimNumber, list));
	}
	return 0;
}
