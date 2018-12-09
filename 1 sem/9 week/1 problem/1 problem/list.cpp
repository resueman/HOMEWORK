#include "list.h"
#include <iostream>

struct ListElement;

struct List
{
	ListElement* head = nullptr;
	int lenght = 0;
};

struct ListElement
{
	ListElement* next = nullptr;
	std::string word = "";
	int counterOfReiterations = 1;
};

List* createList()
{
	return new List;
}

void deleteList(List* list)
{
	if (list == nullptr)
	{
		return;
	}
	while (!isEmpty(list))
	{
		auto temp = list->head;
		list->head = temp->next;
		delete temp;
	}
	delete list;
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

void push(List* list, const std::string &str)
{
	auto newElement = new ListElement{ list->head, str, 1 };	
	list->head = newElement;
}

void addToList(List *&list, const std::string &str, int &countNumberOfLists)
{
	if (list == nullptr)
	{
		list = createList();
		countNumberOfLists++;
	}
	auto current = findElement(list, str);
	if (current != nullptr)
	{
		++current->counterOfReiterations;
	}
	else
	{
		push(list, str);
		++list->lenght;
	}
}

void printList(List* list)
{
	if (list == nullptr)
	{
		return;
	}
	auto current = list->head;
	while (current != nullptr)
	{
		std::cout << current->word << " " << current->counterOfReiterations << std::endl;
		current = current->next;
	}
	std::cout << std::endl;
}

int getListLenght(List* list)
{
	return list->lenght;
}

int getNumberOfIterations(ListElement* element)
{
	return element->counterOfReiterations;
}

ListElement* findElement(List* list, std::string str)
{
	auto current = list->head;
	while (current != nullptr && current->word != str)
	{
		current = current->next;
	}
	return current;
}

int getCounterOfReiterations(ListElement* element)
{
	return element->counterOfReiterations;
}
