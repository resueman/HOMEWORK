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

void deleteGraph(Graph *&graph)
{
	delete graph;
	graph = nullptr;
}

void addToGraph(Graph* graph, const int element, const int linePosition, const int columnPosition)
{
	graph->verticesMatrix[linePosition][columnPosition] = element;
	graph->verticesMatrix[columnPosition][linePosition] = element;
}

void printAdjMatrix(Graph* graph) 
{
	for (int i = 0; i < graph->verticesMatrix.size(); ++i)
	{
		for (int j = 0; j < graph->verticesMatrix[i].size(); ++j)
		{
			std::cout << graph->verticesMatrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}