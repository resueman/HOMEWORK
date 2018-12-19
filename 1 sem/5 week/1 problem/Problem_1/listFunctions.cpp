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
};

List* createList()
{
	return new List;
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

Element *previousLessElement(List* list, const int data)
{
	if (isEmpty(list) || data <= list->head->data)
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

void addElement(List* list, int value)
{
	auto elemToAdd = new Element{ value, nullptr };
	if (isEmpty(list))
	{
		list->head = elemToAdd;
		return;
	}
	auto previousElement = previousLessElement(list, elemToAdd->data);
	if (previousElement != nullptr)//middle
	{
		if (previousElement->next == nullptr)//tail
		{
			previousElement->next = elemToAdd;
			return;
		}
		elemToAdd->next = previousElement->next;
		previousElement->next = elemToAdd;
	}
	else if (list->head->data > value)//head
	{
		elemToAdd->next = list->head;
		list->head = elemToAdd;
	}
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
	auto previous = previousLessElement(list, valueToDelete);
	
	if (!isEmpty(list) && valueToDelete == list->head->data)
	{
		deleteHead(list);
	}
	else if (!previous || previous->data != valueToDelete)
	{
		std::cout << "No such element in a list";
		return;
	}
	else if (previous->next == nullptr)
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
