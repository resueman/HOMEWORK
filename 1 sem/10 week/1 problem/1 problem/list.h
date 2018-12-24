#pragma once

struct AdjVertList;

struct AdjVertex;

///create list
AdjVertList* createList();

///delete list
void deleteList(AdjVertList *list);

///if list is empty, return true, else return false
bool isEmpty(AdjVertList* list);

///add vertex to adjacent list of another vertex
void add(AdjVertList*& list, const int adjCity, const int pathLenght);

///return list head
AdjVertex* getHead(AdjVertList* list);

///return next list element
AdjVertex* getNext(AdjVertex* vertex);

///return path lenght between city(from vector "vertecies") and it's current adjacent vertex(from "AdjVerList")
int getPath(AdjVertex* vertex);

///return the number of current vertex
int getNumber(AdjVertex* vertex);
