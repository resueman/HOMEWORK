#include "list.h"
#include <iostream>
#include <string>

struct Node
{
	int data = 0;
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

void add(List* list, const int data)
{
	auto newNode = new Node{ data, nullptr };
	if (isEmpty(list))
	{
		list->head = newNode;
		list->tail = newNode;
		return;
	}
	list->tail->next = newNode;
	list->tail = list->tail->next;
}

void deleteList(List* list)
{
	while (list->head != nullptr)
	{
		auto* temp = list->head;
		list->head = list->head->next;
		delete temp;
	}
	delete list;
	list = nullptr;
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

void addToBegin(List* newList, const int data)
{
	auto newNode = new Node{ data, newList->head };
	newList->head = newNode;
}

List* reverse(List* list, List* newList)
{
	auto* current = list->head;
	while (current != nullptr)
	{
		addToBegin(newList, current->data);
		current = current->next;
	}
	return newList;
}

std::string printList(List* list)
{
	std::string result = "";
	auto* current = list->head;
	while (current != nullptr)
	{
		result += current->data + "  ";
		current = current->next;
	}
	std::cout << "\n";
	return result;
}
