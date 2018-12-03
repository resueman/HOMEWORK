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
	int lenght = 0;
};

List* createList()
{
	return new List;
}

void addDataFromFileToList(List* list, std::string &name, std::string &number)
{
	auto newPerson = new Node{ name, number, nullptr };
	if (isEmpty(list))
	{
		list->head = newPerson;
	}
	else
	{
		list->tail->next = newPerson;
	}
	list->tail = newPerson;
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

void deleteList(List* list)
{
	while (list->head != list->tail)
	{
		Node *temp = list->head;
		list->head = list->head->next;
		delete temp;
	}
	delete list->head;
	delete list;
	list = nullptr;
}

void printList(List* list)
{
	Node* current = list->head;
	while (current != nullptr)
	{
		std::cout << current->name << "   " << current->number << "\n";
		current = current->next;
	}
	std::cout << "\n\n";
}

int listLenght(List* list)
{
	return list->lenght;
}

void increaseLenght(List* list)
{
	list->lenght++;
}

Node* getHead(List* list)
{
	return list->head;
}

Node* getNext(Node* node)
{
	return node->next;
}

std::string* getName(Node* node)
{
	return &node->name;
}

std::string* getNumber(Node* node)
{
	return &(node->number);
}

void copyList(List* list, std::string* name, std::string* number)
{
	Node* elementToCopy = new Node{ *name, *number, nullptr };
	if (isEmpty(list))
	{
		list->head = elementToCopy;
	}
	else
	{
		list->tail->next = elementToCopy;
	}
	list->tail = elementToCopy;
	list->lenght++;
}

void copyElement(Node *&nodeTo, Node *&nodeFrom)
{
	nodeTo->name = nodeFrom->name;
	nodeTo->number = nodeFrom->number;
}
