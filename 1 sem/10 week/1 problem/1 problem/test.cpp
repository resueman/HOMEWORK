#include "test.h"
#include "readFromFile.h"

#include <iostream>

using namespace std;

bool test()
{
	set<int> noStateVertecies;
	vector<int> states;

	//Test1
	Graph* graph1 = createGraph();
	readFromFile("test1.txt", graph1, states, noStateVertecies);
	distributeCities(graph1, states, noStateVertecies);
	vector<int> result1 = getAnswer(graph1);
	vector<int> desiredResult1 = {1, 1, 4, 6, 6, 4, 6, 4};
	if (result1 != desiredResult1)
	{
		deleteGraph(graph1);
		return false;
	}
	cout << "Test 1 passed!!!\n";
	deleteGraph(graph1);
	noStateVertecies.clear();
	states.clear();

	//Test2
	Graph* graph2 = createGraph();
	readFromFile("test2.txt", graph2, states, noStateVertecies);
	distributeCities(graph2, states, noStateVertecies);
	vector<int> result2 = getAnswer(graph2);
	vector<int> desiredResult2 = {1, 2, 3};
	if (result2 != desiredResult2)
	{
		deleteGraph(graph2);
		return false;
	}
	cout << "Test 2 passed!!!\n";
	deleteGraph(graph2);
	noStateVertecies.clear();
	states.clear();
	
	//Test3
	Graph* graph3 = createGraph();
	readFromFile("test3.txt", graph3, states, noStateVertecies);
	distributeCities(graph3, states, noStateVertecies);
	vector<int> result3 = getAnswer(graph3);
	vector<int> desiredResult3 = {9, 9, 9, 4, 4, 4, 4, 4, 9, 4, 9};
	if (result3 != desiredResult3)
	{
		deleteGraph(graph3);
		return false;
	}
	cout << "Test 3 passed!!!\n";
	deleteGraph(graph3);
	noStateVertecies.clear();
	states.clear();
	
	cout << "\nAll tests passed successfully ;)\n\n";
	return true;
}
