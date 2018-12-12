#pragma once

struct List;

List* createList();

void add(List* list, const int adjCity, const int pathLenght);

bool isEmpty(List* list);

void deleteList(List *list);
