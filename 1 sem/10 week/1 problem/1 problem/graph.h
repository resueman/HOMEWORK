#pragma once

#include <vector>

struct Graph;

Graph* createGraph();

void deleteGraph(Graph* graph);

void distributeCities(Graph* graph, std::vector<int> &states);

void printResult(Graph* graph, std::vector<int> &states);

void changeState(Graph* graph, const int &vertexNumber, const int &newState);

void addToAdjList(Graph* graph, const int &city,const int &adjCity,const int &pathLenght);

void addToSet(Graph* graph, const int &city, bool result);