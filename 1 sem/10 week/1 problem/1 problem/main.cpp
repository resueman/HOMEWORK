#include "readFromFile.h"

using namespace std;

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
	vector<int> states;
	readFromFile("file.txt", graph, states);
	distributeCities(graph, states);
	printResult(graph, states);
	deleteGraph(graph);

	return 0;
}