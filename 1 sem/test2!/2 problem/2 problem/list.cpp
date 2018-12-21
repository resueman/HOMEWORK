#include "list.h"
#include <iostream>

struct Node
{
	int data = 0;
	Node* next = nullptr;
};

struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int length = 0;
};

List* createList()
{
	return new List;
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
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

void addNode(List* list, const int position, const int data)
{
	auto newNode = new Node{ data, nullptr };
	if (isEmpty(list))
	{
		list->head = newNode;
		list->tail = newNode;
	}
	else if (position == list->length + 1)
	{
		list->tail->next = newNode;
		list->tail = list->tail->next;
		
	}
	else if (position == 1)
	{
		newNode->next = list->head;
		list->head = newNode;
	}
	else if (position <= 0 || position > list->length)
	{
		std::cout << "No such position";
		return;
	}
	else
	{
		auto current = list->head;
		for (int i = 1; i < position - 1; ++i)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	++list->length;
}

void deleteNode(List* list, const int position)
{
	if (position <= 0 || position > list->length)
	{
		std::cout << "No such position";
		return;
	}
	else if (isEmpty(list))
	{
		std::cout << "List is empty!\n";
		return;
	}
	else if (position == 1)
	{
		auto* temp = list->head;
		list->head = temp->next;
		delete temp;
	}
	else
	{
		auto current = list->head;
		for (int i = 1; i < position - 1; ++i)
		{
			current = current->next;
		}
		auto* temp = current->next;
		current->next = temp->next;
		delete temp;
	}
	--list->length;
}

std::string printList(List* list)
{
	auto* current = list->head;
	std::string result = "";
	while (current != nullptr)
	{
		result = current->data + "  ";
		current = current->next;
	}
	return result;
}