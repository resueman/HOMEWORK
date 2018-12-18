#pragma once

#include <string>

struct List;

///creates list
List* createList();

///delete list
void deleteList(List* list);

///check if list is empty
bool isEmpty(List* list);

///add element to list by position
void addElement(List* list, const int value, const int position);

///add element to list by position
void deleteElement(List* list, const int position);

///this function prints list
std::string printList(List* list);
