#include "graphBuilding.h"

#include <iostream>

using namespace std;

int main()
{
	Graph* graph = graphBuilding("file.txt");
	printGraph(graph);
	vector<bool> answer = search(graph);
	printAnswer(graph, answer);
	deleteGraph(graph);

	return 0;
}