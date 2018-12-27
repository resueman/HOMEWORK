#include "listFunctions.h"
#include <iostream>

struct Element
{
	int data = 0;
	Element* next = nullptr;
};

struct List
{
	Element* head = nullptr;
	Element* tail = nullptr;
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
		list->tail = elemToAdd;
		return;
	}
	if (list->head->data >= value)//head
	{
		elemToAdd->next = list->head;
		list->head = elemToAdd;
		return;
	}
	if (value >= list->tail->data)
	{
		list->tail->next = elemToAdd;
		list->tail = list->tail->next;//tail
	}
	else
	{
		auto previousElement = previousLessElement(list, elemToAdd->data);
		elemToAdd->next = previousElement->next;//middle
		previousElement->next = elemToAdd;
	}
}

Element* previousLessElement(List* list, const int data)
{
	Element* previous = list->head;
	while (previous->next != nullptr && previous->next->data < data)
	{
		previous = previous->next;
	}
	return previous;
}

Element* getNodeIfExists(List* list, const int data)
{
	auto current = list->head;
	while (current->next != nullptr && current->next->data <= data)
	{
		if (current->next->data == data)
		{
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

void deleteHead(List* list)
{
	if (list->head == list->tail)
	{
		Element* temp = list->head;
		delete temp;
		list->head = nullptr;
		list->tail = nullptr;
		return;
	}
	Element* temp = list->head;
	list->head = list->head->next;
	delete temp;
}

void deleteTail(List* list)
{
	auto current = list->head;
	while (current->next != list->tail)
	{
		current = current->next;
	}
	auto* temp = list->tail;
	list->tail = current;
	current->next = nullptr;
	delete temp;
}

void deleteMiddle(List* list, Element* elementToDeletePrev)
{
	auto* temp = elementToDeletePrev->next;
	elementToDeletePrev->next = elementToDeletePrev->next->next;
	delete temp;
}

void whatToDelete(List* list, int valueToDelete)
{	
	if (isEmpty(list))
	{
		std::cout << "List is empty, nothing to delete\n";
		return;
	}
	if (valueToDelete == list->head->data)
	{
		deleteHead(list);
		return;
	}
	if (list->tail->data == valueToDelete)
	{
		deleteTail(list);
		return;
	}
	auto previous = getNodeIfExists(list, valueToDelete);
	if (previous == nullptr)
	{
		std::cout << "No such element in a list\n";
		return;
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
	std::cout << "\n\n";
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

