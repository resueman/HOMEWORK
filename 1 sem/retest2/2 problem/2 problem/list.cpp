#include <iostream>
#include "list.h"

using namespace std;

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
	int lenght = 0;
};

List* createList()
{
	return new List;
}

void deleteList(List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	while (list->head != list->tail)
	{
		auto temp = list->head;
		list->head = list->head->next;
		delete temp;
	}
	delete list->head;
	list->head = nullptr;
	list->tail = nullptr;
	delete list;
}

string printList(List* list)
{
	string result = "";
	if (isEmpty(list))
	{
		result = "No elements in list\n";
		return result;
	}
	auto current = list->head;
	while (current != nullptr)
	{
		result +=  to_string(current->data) + " ";
		current = current->next;
	}
	return result;
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

Element* getElementByPosition(List* list, const int position)
{
	Element* desired = list->head;
	for (int i = 0; i < position; ++i)
	{
		desired = desired->next;
	}
	return desired;
}

void addHead(List* list, Element* newElement)
{
	newElement->next = list->head;
	list->head->prev = newElement;
	list->head = newElement;
}

void addTail(List* list, Element* newElement)
{
	list->tail->next = newElement;
	newElement->prev = list->tail;
	list->tail = newElement;
}

void addMiddle(List* list, Element* newElement, const int position)
{
	Element* toAdd = getElementByPosition(list, position);
	newElement->next = toAdd;
	newElement->prev = toAdd->prev;
	toAdd->prev->next = newElement;
	toAdd->prev = newElement;
}

void addElement(List* list, const int value, const int position)
{
	auto newElement = new Element{ value, nullptr, nullptr };

	if (isEmpty(list))
	{
		list->head = newElement;
		list->tail = newElement;
	}
	else
	{
		if (position == 0)
		{
			addHead(list, newElement);
		}
		else if (position == list->lenght)
		{
			addTail(list, newElement);
		}
		else
		{
			addMiddle(list, newElement, position);
		}
	}
	++list->lenght;
}

void deleteHead(List* list)
{
	if (list->head == list->tail)
	{
		delete list->head;
		list->head = nullptr;
		list->tail = nullptr;
		return;
	}
	Element* temp = list->head;
	temp->next->prev = nullptr;
	list->head = temp->next;
	delete temp;
}

void deleteTail(List* list)
{
	Element* temp = list->tail;
	temp->prev->next = nullptr;
	list->tail = temp->prev;
	delete temp;
}

void deleteMiddle(List* list, const int position)
{
	Element* toDelete = getElementByPosition(list, position);
	toDelete->prev->next = toDelete->next;
	toDelete->next->prev = toDelete->prev;
	delete toDelete;
}

void deleteElement(List* list, const int position)
{
	if (isEmpty(list))
	{
		return;
	}
	if (position == 0)
	{
		deleteHead(list);
	}
	else if (position == list->lenght - 1)
	{
		deleteTail(list);
	}
	else
	{
		deleteMiddle(list, position);
	}
	--list->lenght;
}
