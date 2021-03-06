#pragma once

#include <string> 

struct Set;

///function that creates set
Set* createSet();

///delete set
void deleteSet(Set* set);

///check if set already contains element, is it empty
bool addToSet(Set* set, int const  data);

///check if set is empty, if it contains element we want to delete
bool removeFromSet(Set* set, int const data);

///check if element exists in a set
bool exists(Set* set, int const data);

///check if set is empty
bool isEmpty(Set* set);

///print tree elements in a descending order
std::string  printDescendingOrder(Set* set);

///print tree elements in an ascending order
std::string  printAscendingOrder(Set* set);
