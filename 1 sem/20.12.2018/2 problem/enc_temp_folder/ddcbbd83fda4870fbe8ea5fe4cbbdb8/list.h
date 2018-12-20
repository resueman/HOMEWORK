#pragma once

#include <string>

struct List;

///create list
List* createList();

///delete list
void deleteList(List* list);

///if list is empty return true, else return false
bool isEmpty(List* list);

///add data to list
void add(List* list, const std::string &data);

///print list
void printList(List* list);

List* getResult(List* list);

bool check(List* resultList);

