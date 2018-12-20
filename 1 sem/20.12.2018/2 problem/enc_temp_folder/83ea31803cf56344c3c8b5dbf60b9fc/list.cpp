#include "list.h"
#include <iostream>

struct Node
{
	std::string data = "";
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

void deleteList(List* list)
{
	while (list->head != list->tail)
	{
		auto* temp = list->head;
		list->head = temp->next;
		delete temp;
	}
	delete list->head;
	delete list;
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

void add(List* list, const std::string &data)
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
	++list->lenght;
}

void printList(List* list)
{
	if (isEmpty(list))
	{
		std::cout << "No elements in a list";
		return;
	}
	auto* current = list->head;
	while (current != nullptr)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
}

List* getResult(List* list)
{
	List* resultList = createList();
	if (isEmpty(list))
	{
		return resultList;
	}
	add(resultList, list->head->data);
	auto currentI = list->head;
	for (int i = 0; i < list->lenght; ++i)
	{
		auto currentJ = list->head;
		for (int j = 0; j < i; ++j)
		{
			if (currentJ->data == currentI->data)
			{
				break;
			}
			currentJ = currentJ->next;
		}
		if (currentI == currentJ)
		{
			add(resultList, currentI->data);
		}
		currentI = currentI->next;
	}
	return list;
}

bool check(List* resultList)
{
	if (isEmpty(resultList))
	{
		return true;
	}
	auto str = resultList->head;
	while (str != nullptr)
	{
		auto current = resultList->head->next;
		while (current->next != str)
		{
			if (current->data == str->data)
			{
				return false;
			}
			current = current->next;
		}
		str = str->next;
	}
	return true;
}
