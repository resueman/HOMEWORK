#pragma once

struct Node;

struct Set
{
	Node* root = nullptr;
};

struct Node
{
	int data = 0;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
};

Set* createSet();
void deleteSet(Set* set, Node* node);
bool addToSet(Set* set, int const  data);
bool removeFromSet(Set* set, int const data);
bool exists(Set* set, int const data);
bool isEmpty(Set* set);
void removeNode(Node*& current, int const data);
int maximum(Node* current);
void addNode(Node* node, int const data);
