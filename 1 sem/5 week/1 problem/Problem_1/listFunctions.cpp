#include <iostream>
#include "listFunctions.h"

Element *previousLessElement(List &list, Element* current)
{
	Element* previous = list.head;
	while (previous->next != nullptr && previous->next->data < current->data)
	{
		previous = previous->next;
	}
	return previous;
}

void addElement(List &list, int value)
{
	auto elemToAdd = new Element{ value, nullptr };
	if (isEmpty(list))
	{
		list.head = elemToAdd;
	}
	else
	{
		if (value < list.head->data)
		{
			elemToAdd->next = list.head;
			list.head = elemToAdd;
		}
		else
		{
			elemToAdd->next = previousLessElement(list, elemToAdd)->next;
			previousLessElement(list, elemToAdd)->next = elemToAdd;
		}
	}
}

Element* previousElement(List& list, Element* current)
{
	Element* previous = list.head;
	while (previous->next != current)
	{
		previous = previous->next;
	}
	return previous;
}

void deleteHead(List &list)
{
	if (list.head->next == nullptr)
	{
		list.head = nullptr;
		delete list.head;
	}
	else
	{
		Element* temp = list.head;
		list.head = list.head->next;
		delete temp;
	}
}

void deleteTail(List &list, Element *elementToDelete)
{
	previousElement(list, elementToDelete)->next = nullptr;
	delete elementToDelete;
}

void deleteMiddle(List &list, Element *elementToDelete)
{
	previousElement(list, elementToDelete)->next = elementToDelete->next;
	delete elementToDelete;
}

void whatToDelete(List &list, int valueToDelete)
{
	auto *elementToDelete = list.head;
	while ((elementToDelete != nullptr) && (elementToDelete->data != valueToDelete))
	{
		elementToDelete = elementToDelete->next;
	}
	if (elementToDelete == nullptr)
	{
		std::cout << "No such element in a list\n";
	}
	else
	{
		if (elementToDelete == list.head)
		{
			deleteHead(list);
		}
		else if (elementToDelete->next == nullptr)
		{
			deleteTail(list, elementToDelete);
		}
		else
		{
			deleteMiddle(list, elementToDelete);
		}
	}
}

bool isEmpty(List &list)
{
	return list.head == nullptr;
}

void printList(List &list)
{
	if (isEmpty(list))
	{
		std::cout << "No elements in list\n";
	}
	auto* current = list.head;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
}