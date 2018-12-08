#include "list.h"

struct ListElement;

struct List
{
	ListElement* head = nullptr;
};

struct ListElement
{
	ListElement* next = nullptr;
	std::string word = "";
	int counterOfReiterations = 1;
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
		list->head = temp->next;
		delete temp;
	}
	list = nullptr;
	delete list;
}

void pop(List* list, const std::string &str)
{
	ListElement* temp = list->head;
	list->head = list->head->next;
	delete temp;
}

void push(List* list, const std::string &str)
{
	auto newElement = new ListElement{ list->head, str, 1 };	
	list->head = newElement;
}

void addToList(List* list, std::string &str)
{
	if (isEmpty(list))
	{
		push(list, str);
		return;
	}
	auto current = list->head;
	while (current != nullptr && current->word != str)
	{
		current = current->next;
	}
	if (current == nullptr)
	{
		push(list, str);
	}
	else
	{
		++current->counterOfReiterations;
	}
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

int maxListLenght(List* list)
{

}

int averageListLength(List* list)
{

}
