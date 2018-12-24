#include "readFromFile.h"
#include "test.h"

#include <iostream>

using namespace std;

int main()
{
	if (!test())
	{
		cout << "\nNot all tests passed successfully ;(\n";
		return -1;
	}

	Graph* graph = createGraph();
	set<int> noStateVertecies;
	vector<int> states;
	readFromFile("file.txt", graph, states, noStateVertecies);
	distributeCities(graph, states, noStateVertecies);
	printResult(graph, states);
	deleteGraph(graph);
	
	return 0;
}
