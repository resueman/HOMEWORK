#include "test.h"

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
	bool result1 = false;
	result1 = ;
	if (!result1)
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
	bool result2 = false;
	result2 = ;
	if (!result2)
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
	bool result3 = false;
	result3 = ;
	if (!result3)
	{
		deleteGraph(graph3);
		return false;
	}
	cout << "Test 3 passed!!!\n";
	deleteGraph(graph3);
	noStateVertecies.clear();
	states.clear();
	
	cout << "All tests passed successfully ;)\n";
	return true;
}
