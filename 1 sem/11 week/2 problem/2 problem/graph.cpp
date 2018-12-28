#include "priorityQueue.h"
#include "graph.h"
#include <vector>
#include <iostream>

using namespace std;

struct Graph
{
	vector<vector<int>> verticesMatrix;
};

Graph* createGraph(const int numberOfVertices)
{
	auto graph = new Graph;
	graph->verticesMatrix.resize(numberOfVertices);
	for (int i = 0; i < numberOfVertices; ++i)
	{
		graph->verticesMatrix[i].resize(numberOfVertices);
	}
	return graph;
}

void deleteGraph(Graph*& graph)
{
	delete graph;
	graph = nullptr;
}

void addToGraph(Graph* graph, const int element, const int linePosition, const int columnPosition)
{
	graph->verticesMatrix[linePosition][columnPosition] = element;
	graph->verticesMatrix[columnPosition][linePosition] = element;
}

Graph* primFindMST(Graph* graph)
{
	vector<bool> belongToMST;
	belongToMST.resize(graph->verticesMatrix.size());
	for (int i = 0; i < graph->verticesMatrix.size(); ++i)
	{
		belongToMST[i] = false;
	}

	Queue* priorityQueue = createQueue();
	Graph* minSpanningTree = createGraph(graph->verticesMatrix.size());
	int numberOfVerticesBelongToMST = 1;
	int currentVertex = 0;
	while (numberOfVerticesBelongToMST < graph->verticesMatrix.size())
	{
		for (int j = 0; j < graph->verticesMatrix.size(); ++j)
		{
			if (graph->verticesMatrix[currentVertex][j] != 0 && minSpanningTree->verticesMatrix[currentVertex][j] == 0)
			{
				enqueue(priorityQueue, currentVertex, j, graph->verticesMatrix[currentVertex][j]);
			}
		}

		currentVertex = getHeadBegin(priorityQueue);
		int nextVertex = getHeadEnd(priorityQueue);
		dequeue(priorityQueue);

		while (belongToMST[currentVertex] && belongToMST[nextVertex])
		{
			currentVertex = getHeadBegin(priorityQueue);
			nextVertex = getHeadEnd(priorityQueue);
			dequeue(priorityQueue);
		}

		addToGraph(minSpanningTree, graph->verticesMatrix[currentVertex][nextVertex], currentVertex, nextVertex);
		belongToMST[currentVertex] = true;
		belongToMST[nextVertex] = true;
		currentVertex = nextVertex;
		++numberOfVerticesBelongToMST;
	}
	deleteQueue(priorityQueue);
	return minSpanningTree;
}

void printGraph(Graph* graph)
{
	for (int i = 0; i < graph->verticesMatrix.size(); ++i)
	{
		for (int j = 0; j < graph->verticesMatrix.size(); ++j)
		{
			cout << graph->verticesMatrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

int data(Graph* graph, const int line, const int column)
{
	return graph->verticesMatrix[line][column];
}
