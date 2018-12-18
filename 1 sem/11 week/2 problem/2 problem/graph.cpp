#include <vector>
#include <iostream>
using namespace std;

struct Graph
{
	vector<std::vector<int>> edges;

};

Graph* createGraph()
{
	return new Graph;
}

void deleteGraph(Graph* graph)
{
	delete graph;
	graph = nullptr;
}