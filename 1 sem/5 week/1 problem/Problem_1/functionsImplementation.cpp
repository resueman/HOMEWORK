#include <string>//for to_string function(used in printList())
#include <iostream>
#include "functionsDeclaration.h"

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
	if (list.head == nullptr)
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

void printList(List &list)
{
	std::string resultStr = "";
	auto* current = list.head;
	if (current == nullptr)
	{
		std::cout << "No elements in list\n";
	}
	while (current != nullptr)
	{
		resultStr += std::to_string(current->data) + " ";
		current = current->next;
	}
	std::cout << resultStr << "\n\n";
}

void deleteList(List &list)
{
	while (list.head != nullptr)
	{
		Element* temp = list.head;
		list.head = temp->next;
		delete temp;
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

