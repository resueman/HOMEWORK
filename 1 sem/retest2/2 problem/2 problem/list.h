#pragma once

struct List;

///creates list
List* createList();

///delete list
void deleteList(List* list);

///check if list is empty
bool isEmpty(List* list);

///add element to list
void addElement(List* list, const int value, const int position);

///determine position of element that should be deleted


///this function prints list :)
void printList(List* list);
