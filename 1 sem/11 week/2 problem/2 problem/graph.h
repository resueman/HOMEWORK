#pragma once

struct Graph;

Graph* createGraph(const int numberOfVertices);

void deleteGraph(Graph*& graph);

void addToGraph(Graph* graph, const int element, const int linePosition, const int columnPosition);

Graph* primFindMST(Graph* graph);

void printGraph(Graph* graph);

int data(Graph* graph, const int line, const int column);
