#pragma once

#include <string>
#include <iostream>

struct List;

///This function creates list
List* createList();

///This function removes list
void deleteList(List* list);

///Add element to list
void pop(List* list, const std::string &str);

///Removes element from list
void push(List* list, const std::string &str);

///if list is empty returns true, else returns false
bool isEmpty(List* list);

///Returns average list lenght
//int averageListLength(List* list);

void addToList(List *&list, std::string &str);

void printList(List* list);
