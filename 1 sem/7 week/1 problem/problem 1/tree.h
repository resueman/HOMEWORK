#pragma once

struct Set;
struct Node;

///function that creates set
Set* createSet();

///delete set
void deleteSet(Set* set, Node* node);

///check if set already contains element, is it empty
bool addToSet(Set* set, int const  data);

///add element
void addNode(Node* node, int const data);

///check if set is empty, if it contains element we want to delete
bool removeFromSet(Set* set, int const data);

///delete element by it's value
void removeNode(Node*& current, int const data);

///check if element exists in a set
bool exists(Set* set, int const data);

///check if set is empty
bool isEmpty(Set* set);

///search max element in a set to put it on deleted element place
int maximum(Node* current);

