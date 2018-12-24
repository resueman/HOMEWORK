#include "tree.h"
#include <iostream>

using namespace std;

int main()
{
	int input = 0;
	cout << "Enter numbers, 0 signs the end of the sequence\n";
	cin >> input;
	Set* tree = createSet();
	while (input != 0)
	{
		addToSet(tree, input);
		cin >> input;
	}
	printAscendingOrder(tree);

	deleteSet(tree);

	return 0;
}