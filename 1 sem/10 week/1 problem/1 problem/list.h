#pragma once

struct List;
struct AdjVertex;
List* createList();

void add(List* list, const int adjCity, const int pathLenght);

bool isEmpty(List* list);

void deleteList(List *list);

AdjVertex* getHead(List* list);
AdjVertex* getNext(AdjVertex* vertex);