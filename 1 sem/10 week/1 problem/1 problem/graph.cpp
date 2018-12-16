#include "graph.h"
#include "list.h"

#include <iostream>

using namespace std;

struct Vertex
{
	int number = 0;
	int state = 0;
	AdjVertList* list = nullptr;
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

Vertex* findVertex(Graph* graph, const int vertexNumber)
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

void addToSet(Graph* graph, const int city, bool result)
{
	if (!result)
	{
		return;
	}
	auto newVertex = new Vertex{ city, 0, nullptr };
	graph->vertices.push_back(newVertex);
}

void addToAdjList(Graph* graph, const int city, const int adjCity, const int pathLenght)
{
	Vertex* vertex = findVertex(graph, city); 
	add(vertex->list, adjCity, pathLenght);
}

void changeState(Graph* graph, const int vertexNumber, const int newState)
{
	auto vertex = findVertex(graph, vertexNumber);
	if (vertex != nullptr)
	{
		vertex->state = newState;
	}
}

bool assignCity(Graph* graph, int capital, set<int>& noStateVertecies)
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
				if (currentPath < minPath && noStateVertecies.find(currentNumber) != noStateVertecies.end())
				{
					minPath = currentPath;
					candidate = currentNumber;
				}
				current = getNext(current);
			}
		}
	}
	changeState(graph, candidate, capital);
	noStateVertecies.erase(candidate);

	return noStateVertecies.empty();
}

void distributeCities(Graph* graph, vector<int> &states, set<int> &noStateVertecies)
{	
	while (true)
	{
		for (int i = 0; i < states.size(); ++i)
		{
			if (assignCity(graph, states[i], noStateVertecies))
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
		cout << "Cities:  ";
		for (int j = 0; j < graph->vertices.size(); ++j)
		{
			if (states[i] == graph->vertices[j]->state && states[i] != graph->vertices[j]->number)
			{
				cout << graph->vertices[j]->number << "  ";
			}
		}
		cout << "\n\n";
	}
}

vector<int> getAnswer(Graph* graph)
{
	vector<int> answers;
	for (int i = 0; i < graph->vertices.size(); ++i)
	{
		answers.push_back(graph->vertices[i]->state);
	}
	return answers;
}
