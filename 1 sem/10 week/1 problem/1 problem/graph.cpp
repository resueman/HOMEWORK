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

void buildGraph(Graph* graph, const int numberOfCities)
{
	graph->vertices.resize(numberOfCities);
	for (int i = 0; i < numberOfCities; ++i)
	{
		graph->vertices[i]->list = createList();
	}
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
	return nullptr;
}

void addVertexToGraph(Graph* graph, int &city, int &adjCity, int &pathLenght)
{
	if (find(graph->vertices.begin(), graph->vertices.end(), city) == graph->vertices.end())
	{
		auto newVertex = new Vertex{ city, 0, nullptr };
		graph->vertices.push_back(newVertex);
		add(newVertex->list, adjCity, pathLenght);
		return;
	}
	auto vertex = findVertex(graph, city);
	add(vertex->list, adjCity, pathLenght);
}

void assignToState(Graph* graph, int &vertexNumber, int &newState)
{
	auto vertex = findVertex(graph, vertexNumber);
	vertex->state = newState;
}

bool assignCity(Graph* graph, int capital)
{

}

void distributeCities(Graph* graph, const int numberOfStates, const int numberOfCities)
{	
	bool allHaveState = false;
	while (!allHaveState)
	{

	}
}

void printResult(Graph* graph)
{

}
