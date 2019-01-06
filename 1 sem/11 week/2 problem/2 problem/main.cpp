#include "graphBuilding.h"
#include "test.h"
#include <iostream>

using namespace std;

int main()
{
	if (!test())
	{
		cout << ":(";
		return 1;
	}
	Graph* graph = graphBuilding("file.txt");
	Graph* minSpanningTree = primFindMST(graph);
	printGraph(graph);
	printGraph(minSpanningTree);
	deleteGraph(graph);
	deleteGraph(minSpanningTree);

	return 0;
}
