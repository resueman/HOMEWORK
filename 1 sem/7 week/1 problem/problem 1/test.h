#pragma once

#include "tree.h"
#include <string> 
#include <fstream>
#include <istream>
#include <iostream>

bool test();
int readFromFile(Set* set);
void printDescendingOrder(Set* set, std::string &resultStr);
void printAscendingOrder(Set* set, std::string &resultStr);