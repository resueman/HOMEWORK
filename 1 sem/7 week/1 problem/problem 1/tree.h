#pragma once

struct Node;

struct Set
{
	Node* root;
};

Set* createSet();
void deleteSet(Set* set, Node* node);
bool addToSet(Set* set, int const  data);
bool removeFromSet(Set* set, int const data);
bool exists(Set* set, int const data);
bool isEmpty(Set* set);