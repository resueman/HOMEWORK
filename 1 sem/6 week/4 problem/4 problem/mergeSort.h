#pragma once

void splitList(List* list, List *&leftList, List *&rightList);
void merge(List *&list, List *&leftList, List *&rightList, bool byName);
void mergeSortRecursive(List* list, bool byName);
