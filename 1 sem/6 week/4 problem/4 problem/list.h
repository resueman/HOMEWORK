#pragma once

#include <string>

struct List;
struct Node;

///creates new instance of list
List* createList();

///if list is empty, function returns true, else it returns false
bool isEmpty(List* list);

///add data from file to list
void addDataFromFileToList(List* list, std::string &name, std::string &number);

///prints elements of list
void printList(List* list);

///function, that delete list
void deleteList(List* list);

///returns list lenght
int listLenght(List* list);

///increase value of list lenght
void increaseLenght(List* list);

///returns pointer on next element
Node* getNext(Node* node);

///returns name
std::string* getName(Node* node);

///reurns number
std::string* getNumber(Node* node);

///returns list head
Node* getHead(List* list);

///copy element from one list to another(use in split)
void copyList(List* list, std::string* name, std::string* number);

///copy elements (which remain in list, after ending of another list) to result list 
void copyElement(Node *&nodeTo, Node *&nodeFrom);
