#pragma once
#include <string>

struct List;
struct Node;

///create list
List* createList();

///delete list
void deleteList(List* list);

///if list is empty return true, else return false
bool isEmpty(List* list);

///add data to list
void add(List* list, const int data);

///print list
std::string printList(List* list);

///reverse list
List* reverse(List* list, List* newList);

