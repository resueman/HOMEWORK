#include "readFromFile.h"
#include <set>

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
	distributeCities(graph, noStateVertecies);
	//printResult(graph);
	deleteGraph(graph);

	return 0;
}