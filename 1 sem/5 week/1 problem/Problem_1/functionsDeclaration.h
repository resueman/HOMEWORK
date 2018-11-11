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
///determine where to insert element by location of max element, which less than added item
Element *previousLessElement(List &list, Element* current);
///this function prints list :)
void printList(List &list);
///determine position of element that should be deleted
void whatToDelete(List &list, int elementToDelete);
///return pointer on previous element of current element
Element* previousElement(List &list, Element* current); 
///delete smallest element
void deleteHead(List &list);
///delete element, that isn't biggest or smallest
void deleteMiddle(List &list, Element *elementToDelete);
///delete last(the biggest) element of list
void deleteTail(List &list, Element *elementToDelete);
///delete list 
void deleteList(List& list);
