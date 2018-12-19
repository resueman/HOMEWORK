#include "graphBuilding.h"

#include <iostream>

using namespace std;

int main()
{
	/*if (!test())
	{
		cout << ":(";
		return 1;
	}
	*/
	Graph* graph = graphBuilding("file.txt");



	deleteGraph(graph);

	return 0;
}