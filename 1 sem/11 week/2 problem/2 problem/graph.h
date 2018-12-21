#pragma once

struct Graph;

Graph* createGraph(const int numberOfVertices);

void deleteGraph(Graph*& graph);

void addToGraph(Graph* graph, const int element, const int linePosition, const int columnPosition);

Graph* primFinfMST(Graph* graph);

void printGraph(Graph* graph);
