#pragma once

#include <vector>

struct Graph;

Graph* createGraph(const int numberOfVertices);

void deleteGraph(Graph*& graph);

void addToGraph(Graph* graph, const int element, const int linePosition, const int columnPosition);

void printGraph(Graph* graph);

std::vector<bool> search(Graph* graph);

void printAnswer(Graph* graph, std::vector<bool> answer);