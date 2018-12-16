#include "graph.h"
#include "list.h"
#include <iostream>
#include <set>

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

Vertex* findVertex(Graph* graph, const int &vertexNumber)
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

void addToSet(Graph* graph, const int &city, bool result)
{
	if (!result)
	{
		return;
	}
	auto newVertex = new Vertex{ city, 0, nullptr };
	graph->vertices.push_back(newVertex);
}

void addToAdjList(Graph* graph, const int &city, const int &adjCity, const int &pathLenght)
{
	Vertex* vertex = findVertex(graph, city); //why not equal?????? 
	add(vertex->list, adjCity, pathLenght);
}

void changeState(Graph* graph, const int &vertexNumber, const int &newState)
{
	auto vertex = findVertex(graph, vertexNumber);
	vertex->state = newState;
}

bool assignCity(Graph* graph, int capital, set<int>& free)
{
	int candidate = 0;
	int minPath = INT_MAX;
	for (int i = 0; i < graph->vertices.size(); ++i)
	{
		if (graph->vertices[i]->state == capital)
		{
			auto current = getHead(graph->vertices[i]->list);
			while (current != nullptr)
			{
				int currentNumber = getNumber(current);
				int currentPath = getPath(current);
				if (currentPath < minPath && free.find(currentNumber) != free.end())
				{
					minPath = currentPath;
					candidate = currentNumber;
				}
				getNext(current);
			}
		}
	}
	changeState(graph, candidate, capital);
	free.erase(candidate);
	return free.empty();
}

void distributeCities(Graph* graph, vector<int> &states, set<int> &noStateVertecies)
{	
	while (true)
	{
		for (int i = 0; i < states.size(); ++i)
		{
			if (!assignCity(graph, states[i], noStateVertecies))
			{
				return;
			}
		}
	}
}

void printResult(Graph* graph, vector<int> &states)
{
	for (int i = 0; i < states.size(); ++i)
	{
		cout << "Capital:  " << states[i] << endl;
		cout << "Cities\n";
		for (int j; j < graph->vertices.size(); ++j)
		{
			if (states[i] == graph->vertices[j]->state)
			{
				cout << graph->vertices[j]->number;
			}
		}
	}
}
