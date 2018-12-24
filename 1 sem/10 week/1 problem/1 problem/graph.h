#pragma once

#include <vector>
#include <set>
#include <string>

struct Graph;

///create graph
Graph* createGraph();

///delete graph
void deleteGraph(Graph* graph);

///distribute cities between states
void distributeCities(Graph* graph, std::vector<int> &states, std::set<int> &noStateVertecies);

///change state of city(when state assigns city, city gets new state number)
void changeState(Graph* graph, const int vertexNumber, const int newState);

///add vertex to adjacent list
void addToAdjList(Graph* graph, const int city,const int adjCity,const int pathLenght);

///add vertex to set of vertecies(to vector "vertecies")
void addToSet(Graph* graph, const int city, bool result);

///print capitals and cities, which belong to them
void printResult(Graph* graph, std::vector<int> &states);

///returns number of state for each vertex
std::vector<int> getAnswer(Graph* graph);
