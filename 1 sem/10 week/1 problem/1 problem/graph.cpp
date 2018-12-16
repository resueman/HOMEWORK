#include "graph.h"
#include "list.h"
#include <iostream>
#include <algorithm>
#include <queue>
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

bool isContain(Graph* graph, const int &city)
{
	for (auto vertex : graph->vertices)
	{
		if (vertex->number == city)
		{
			return true;
		}
	}
	return false;
}

void addVertexToGraph(Graph* graph, const int &city, const int &adjCity, const int &pathLenght)
{
	if(isContain(graph, city))
	{
		auto newVertex = new Vertex{ city, 0, nullptr };
		graph->vertices.push_back(newVertex);
		add(newVertex->list, adjCity, pathLenght);
		return;
	}
	auto vertex = findVertex(graph, city);
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

void distributeCities(Graph* graph, vector<int> &states)
{	
	set<int> freeVertex;
	for (int i = 0; i < graph->vertices.size(); ++i)
	{
		if (graph->vertices[i]->state == 0)
		{
			freeVertex.insert(graph->vertices[i]->number);
		}
	}
	bool flag = true;
	while (flag)
	{
		for (int i = 0; i < states.size(); ++i)
		{
			flag = assignCity(graph, states[i], freeVertex);
		}
	}
}

void printResult(Graph* graph, vector<int> &states)
{
	int citiesNum = graph->vertices.size();
	int statesNum = states.size();
	vector<vector<int>> st(statesNum, vector<int>(citiesNum));
	for (int i = 0; i < statesNum; ++i)
	{
		st[i][0] = states[i];
		for (int j = 0; j < citiesNum; ++j)
		{
			if (states[i] == graph->vertices[j]->state)
			{
				st[i][j] = graph->vertices[j]->number;
			}
		}
	}

	for (int i = 0; i < states.size(); ++i)
	{
		cout << "State:  " << st[i][0] << endl;
		cout << "Cities\n";
		for (int j = 0; j < graph->vertices.size(); ++j)
		{
			cout << st[i][j] << "\n";
		}
		cout << endl;
	}
}
