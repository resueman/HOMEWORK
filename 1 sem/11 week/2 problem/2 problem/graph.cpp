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

Graph* primFinfMST(Graph* graph)
{
	Queue* priorityQueue = createQueue();
	Graph* minSpanningTree = createGraph(graph->verticesMatrix.size());
	int numberOfVerticesBelongToMST = 0;
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
		int nextVertex = getHeadEnd(priorityQueue);
		dequeue(priorityQueue);//check next
		while (minSpanningTree->verticesMatrix[currentVertex][nextVertex] != 0 && minSpanningTree->verticesMatrix[currentVertex][nextVertex] == 0)
		{
			nextVertex = getHeadEnd(priorityQueue);
			dequeue(priorityQueue);
		}
		addToGraph(minSpanningTree, graph->verticesMatrix[currentVertex][nextVertex], currentVertex, nextVertex);
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
