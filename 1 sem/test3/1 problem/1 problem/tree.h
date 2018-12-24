#pragma once

struct Set;

///function that creates set
Set* createSet();

///delete set
void deleteSet(Set* set);

///check if set already contains element, is it empty
bool addToSet(Set* set, int const  data);

///check if element exists in a set
bool exists(Set* set, int const data);

///check if set is empty
bool isEmpty(Set* set);

///print in ascending order
void printAscendingOrder(Set* set);
