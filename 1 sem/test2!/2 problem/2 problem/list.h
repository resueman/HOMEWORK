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
void addNode(List* list, const int position, const int data);

///add element to list by position
void deleteNode(List* list, const int position);

///this function prints list
std::string printList(List* list);