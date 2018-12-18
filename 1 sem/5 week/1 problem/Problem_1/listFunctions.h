#pragma once

struct List;

struct Element;

///creates list
List* createList();

///delete list
void deleteList(List* list);

///check if list is empty
bool isEmpty(List* list);

///add element to list
void addElement(List* list, int value);

///determine position of element that should be deleted
void whatToDelete(List* list, int elementToDelete);

///this function prints list :)
void printList(List* list);

///returns pointer on list head
Element* getHead(List* list);

///returns pointer on next element
Element* getNext(Element* elementt);

///returns data of element
int getData(Element* element);
