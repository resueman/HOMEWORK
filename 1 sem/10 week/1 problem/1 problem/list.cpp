#include "list.h"

struct AdjVertex
{
	int number = 0;
	int pathLenght = 0;
	AdjVertex* next = nullptr;
};

struct List
{
	AdjVertex* head = nullptr;
};

List* createList()
{
	return new List;
}

void deleteList(List *list)
{
	while (list->head != nullptr)
	{
		AdjVertex *temp = list->head;
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

void add(List* list, const int adjCity, const int pathLenght)
{
	auto newVertex = new AdjVertex{ adjCity, pathLenght, list->head };
	list->head = newVertex;
}

AdjVertex* getHead(List* list)
{
	return list->head;
}

AdjVertex* getNext(AdjVertex* vertex)
{
	return vertex->next;
}

int getPath(AdjVertex* vertex)
{
	return vertex->pathLenght;
}

int getNumber(AdjVertex* vertex)
{
	return vertex->number;
}
