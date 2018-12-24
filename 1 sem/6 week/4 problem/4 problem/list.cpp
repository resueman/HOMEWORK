#include "list.h"
#include <iostream>

struct Node
{
	std::string name = "";
	std::string number = "";
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

void printList(List* list)
{
	auto* current = list->head;
	while (current != nullptr)
	{
		std::cout << current->name << "   " << current->number << "\n";
		current = current->next;
	}
	std::cout << "\n\n";
}

int listLenght(List* list)
{
	return list->length;
}

void increaseLenght(List* list)
{
	list->length++;
}

Node* getHead(List* list)
{
	return list->head;
}

Node* getNext(Node* node)
{
	return node->next;
}

std::string getName(Node* node)
{
	return node->name;
}

std::string getNumber(Node* node)
{
	return node->number;
}

void copyToList(List* list, const std::string &name, const std::string &number)
{
	auto newElement = new Node{ name, number, nullptr };
	if (isEmpty(list))
	{
		list->head = newElement;
	}
	else
	{
		list->tail->next = newElement;
	}
	list->tail = newElement;
	++list->length;
}

void copyElement(Node *&nodeTo, Node *&nodeFrom)
{
	nodeTo->name = nodeFrom->name;
	nodeTo->number = nodeFrom->number;
}
