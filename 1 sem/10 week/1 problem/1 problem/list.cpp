#include "list.h"

struct AdjVertex
{
	int number = 0;
	int pathLenght = 0;
	AdjVertex* next = nullptr;
};

struct AdjVertList
{
	AdjVertex* head = nullptr;
};

AdjVertList* createList()
{
	return new AdjVertList;
}

void deleteList(AdjVertList *list)
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

bool isEmpty(AdjVertList* list)
{
	return list->head == nullptr;
}

void add(AdjVertList*& list, const int adjCity, const int pathLenght)
{
	if (list == nullptr)
	{
		list = createList();
	}
	auto newVertex = new AdjVertex{ adjCity, pathLenght, list->head };
	list->head = newVertex;
}

AdjVertex* getHead(AdjVertList* list)
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
