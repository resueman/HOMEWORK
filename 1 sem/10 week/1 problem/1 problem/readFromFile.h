#pragma once

#include "graph.h"

///read data from file, put it to graph
bool readFromFile(const char* fileName, Graph* graph, std::vector<int> &states, std::set<int> &noStateVertecies);
