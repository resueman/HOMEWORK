#include "graphBuilding.h"

#include <iostream>

using namespace std;

int main()
{
	Graph* graph = graphBuilding("file.txt");
	printGraph(graph);
	search(graph);
	deleteGraph(graph);

	return 0;
}