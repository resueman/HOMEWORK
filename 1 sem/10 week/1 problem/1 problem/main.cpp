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
	set<int> noStateVertecies;
	vector<int> states;
	readFromFile("file.txt", graph, states, noStateVertecies);
	distributeCities(graph, states, noStateVertecies);
	printResult(graph, states);
	deleteGraph(graph);
	
	return 0;
}
