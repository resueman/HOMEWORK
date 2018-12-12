#include "graph.h"
#include "list.h"
#include <iostream>
#include <vector>

using namespace std;

struct Vertex
{
	int number = 0;
	int state = 0;
	List* list = nullptr;
};

struct Graph
{
	vector<Vertex*> vertices;
};

Graph* createGraph()
{
	return new Graph;
}

void deleteGraph(Graph* graph)
{
	for (auto &vertex : graph->vertices)
	{
		deleteList(vertex->list);
		delete vertex;
		vertex = nullptr;
	}
	graph->vertices.clear();
	delete graph;
	graph = nullptr;
}

Vertex* findVertex(Graph* graph, int &vertexNumber)
{
	for (auto &vertex : graph->vertices)
	{
		if (vertex->number == vertexNumber)
		{
			return vertex;
		}
	}
}

void assignToState(Graph* graph, int &vertexNumber, int &newState)
{
	auto vertex = findVertex(graph, vertexNumber);
	vertex->state = newState;
}

void addVertexToGraph(Graph* graph, int &city, int &adjCity, int &pathLenght)
{
	auto vertex = findVertex(graph, city);
	add(vertex->list, adjCity, pathLenght);
}

void distributeCities(Graph* graph)
{

}

void printResult(Graph* graph)
{

}
