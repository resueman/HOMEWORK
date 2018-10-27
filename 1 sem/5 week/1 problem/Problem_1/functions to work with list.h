#pragma once

using namespace std;

struct Element
{
	int data = 0;
	Element* next = nullptr;
	Element* prev = nullptr;
};

struct List
{
	Element* head = nullptr;
	Element* tail = nullptr;
}list, listForTest;

void addElement(List &list, int value)
{	
	auto elemToAdd = new Element{ value, nullptr, list.tail};
	if (list.head == nullptr)
	{
		list.head = elemToAdd;
		list.tail = elemToAdd;
	}
	else 
	{
		list.tail->next = elemToAdd;
		list.tail = elemToAdd;
		while((elemToAdd->prev != nullptr) && (elemToAdd->data < elemToAdd->prev->data))
		{
			int c = elemToAdd->data;
			elemToAdd->data = elemToAdd->prev->data;
			elemToAdd->prev->data = c;
			elemToAdd = elemToAdd->prev;
		}
	}
}

void deleteHead(List &list)
{
	if (list.head == list.tail)
	{
		delete list.tail;
		list.head = nullptr;
		list.tail = nullptr;
	}
	else
	{
		list.head->next->prev = nullptr;
		Element* temp = list.head;
		list.head = list.head->next;
		delete temp;
	}	
}

void deleteTail(List &list)
{
	list.tail->prev->next = nullptr;
	Element* temp = list.tail;
	list.tail = list.tail->prev;
	delete temp;
}

void deleteMiddle(List &list, Element *current)
{
	current->next->prev = current->prev;
	current->prev->next = current->next;
	delete current;
}

void whatToDelete(List &list, int elementToDelete)
{
	auto *current = list.head;
	while ((current != nullptr) && (current->data != elementToDelete)) 
	{
		current = current->next;
	}
	if (current == nullptr)
	{
		cout << "No such element in a list\n";
	}
	else
	{
		if (current == list.head)
		{
			deleteHead(list);
		}
		else if (current == list.tail)
		{
			deleteTail(list);
		}
		else
		{
			deleteMiddle(list, current);
		}
	}
}

void printList(List &list)
{
	string resultStr = "";
	auto* current = list.head;
	if (current == nullptr)
	{
		cout << "No elements in list\n";
	}
	while (current != nullptr)
	{
		resultStr += to_string(current->data) + " ";
		current = current->next;
	}
	cout << resultStr << endl << endl;
}
