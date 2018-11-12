#pragma once

struct Element
{
	int data = 0;
	Element* next = nullptr;
};

struct List
{
	Element* head = nullptr;
};

///add element to list
void addElement(List &list, int value);
///determine position of inserted element
Element *previousLessElement(List &list, Element* current);
///determine position of element that should be deleted
void whatToDelete(List &list, int elementToDelete);
///return pointer on previous element of current element
Element* previousElement(List &list, Element* current); 
///delete first (the smallest) element of sorted list
void deleteHead(List &list);
///delete element, that isn't biggest or smallest
void deleteMiddle(List &list, Element *elementToDelete);
///delete last(the biggest) element of sorted list
void deleteTail(List &list, Element *elementToDelete);
///this function prints list :)
void printList(List &list);
///check if list is empty
bool isEmpty(List &list);
