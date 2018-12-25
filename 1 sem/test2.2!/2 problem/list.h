#pragma once

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

///returns data
int getNumber(Node* node);

///returns pointer on next node
Node* getNext(Node* node);

///returns list head
Node* getHead(List* list);
