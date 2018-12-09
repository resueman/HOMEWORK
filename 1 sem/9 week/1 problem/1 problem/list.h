#pragma once

#include <string>

struct List;
struct ListElement;

///This function creates list
List* createList();

///This function removes list
void deleteList(List* list);

///If list is empty returns true, else returns false
bool isEmpty(List* list);

///Remove element from list
void push(List* list, const std::string &str);

///Add word to list
void addToList(List *&list, const std::string &str, int &countNumberOfBuckets);

///Print list of current bucket
void printList(List* list);

///Return list lenght of current bucket
int getListLenght(List* list);

///returns pointer on list element, where string we need located
ListElement* findElement(List* list, std::string str);

///returns number of reiterations of word (by pointer)
int getCounterOfReiterations(ListElement* element);
