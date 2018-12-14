#pragma once

struct Graph;

Graph* createGraph();

void deleteGraph(Graph* graph);

void distributeCities(Graph* graph);

void printResult(Graph* graph);

void assignToState(Graph* graph, int &vertexNumber, int &newState);

void addVertexToGraph(Graph* graph, int &city, int &adjCity, int &pathLenght);
void buildGraph(Graph* graph, const int numberOfCities);

bool assignCity(Vertex* vertex);