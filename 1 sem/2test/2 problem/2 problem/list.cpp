#include "list.h"
#include <iostream>

struct Node
{
	int number = 0;
	Node* next = nullptr;
};

struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;
};

List* createList()
{
	return new List;
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

void deleteList(List* list)
{
	while (list->head != nullptr)
	{
		auto *temp = list->head;
		list->head = list->head->next;
		delete temp;
	}
	delete list;
}

Node* getHead(List* list)
{
	return list->head;
}

Node* getNext(Node* node)
{
	return node->next;
}

int getNumber(Node* node)
{
	return node->number;
}

void add(List* list, const int data)
{
	auto newElement = new Node{ data, nullptr };
	if (isEmpty(list))
	{
		list->head = newElement;
	}
	else
	{
		list->tail->next = newElement;
	}
	list->tail = newElement;
}
