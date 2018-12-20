#include <iostream>
#include "listFunctions.h"

struct Element
{
	int data = 0;
	Element* next = nullptr;
};

struct List
{
	Element* head = nullptr;
	int maximum = INT_MIN;
};

List* createList()
{
	return new List;
}

Element *previousLessElement(List* list, const int data);

void addElement(List* list, int value)
{
	auto elemToAdd = new Element{ value, nullptr };
	if (isEmpty(list))
	{
		list->head = elemToAdd;
		list->maximum = elemToAdd->data;
		return;
	}
	if (list->head->data >= value)//head
	{
		elemToAdd->next = list->head;
		list->head = elemToAdd;
		return;
	}
	auto previousElement = previousLessElement(list, elemToAdd->data);
	if (value >= list->maximum)
	{
		list->maximum = value;
		previousElement->next = elemToAdd;//tail
	}
	else
	{
		elemToAdd->next = previousElement->next;//middle
		previousElement->next = elemToAdd;
	}
}

Element *previousLessElement(List* list, const int data)
{
	if (data <= list->head->data)
	{
		return nullptr;
	}
	Element* previous = list->head;
	while (previous->next != nullptr && previous->next->data < data)
	{
		previous = previous->next;
	}
	return previous;
}

void deleteHead(List* list)
{
	if (list->head->next == nullptr)
	{
		delete list->head;
	}
	else
	{
		Element* temp = list->head;
		list->head = list->head->next;
		delete temp;
	}
}

void deleteTail(List* list)
{
	auto current = list->head;
	while (current->next->next != nullptr)
	{
		current = current->next;
	}
	current->next = nullptr;
	delete current->next;
}

void deleteMiddle(List* list, Element* elementToDeletePrev)
{
	elementToDeletePrev->next = elementToDeletePrev->next->next;
	delete elementToDeletePrev;
}

void whatToDelete(List* list, int valueToDelete)
{	
	if (isEmpty(list))
	{
		return;
	}
	auto previous = previousLessElement(list, valueToDelete);
	if (valueToDelete == list->head->data)
	{
		deleteHead(list);
		return;
	}
	if (previous == nullptr || previous->data != valueToDelete)
	{
		std::cout << "No such element in a list";
		return;
	}
	if (previous->next == nullptr)
	{
		deleteTail(list);
	}
	else
	{
		deleteMiddle(list, previous);
	}
}

void printList(List* list)
{
	if (isEmpty(list))
	{
		std::cout << "No elements in list\n";
	}
	auto current = list->head;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
}

void deleteList(List* list)
{
	while (!isEmpty(list))
	{
		auto temp = list->head;
		list->head = list->head->next;
		delete temp;
	}
	delete list;
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

Element* getHead(List* list)
{
	return list->head;
}

Element* getNext(Element* element)
{
	return element->next;
}

int getData(Element* element)
{
	return element->data;
}