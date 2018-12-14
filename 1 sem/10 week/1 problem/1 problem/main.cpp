#include "readFromFile.h"
#include "graph.h"

int main()
{
	/*
	if (!test())
	{
		std::cout << "Program doesn't work";
		return -1;
	}
	*/
	Graph* graph = createGraph();
	readFromFile("file.txt", graph);
	distributeCities(graph);
	printResult(graph);
	deleteGraph(graph);

	return 0;
}