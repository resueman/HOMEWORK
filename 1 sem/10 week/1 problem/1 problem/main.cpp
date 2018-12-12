#include "readFromFile.h"
#include "graph.h"

int main()
{
	Graph* graph = createGraph();
	readFromFile("file.txt", graph);
	distributeCities(graph);
	printResult(graph);
	deleteGraph(graph);

	return 0;
}