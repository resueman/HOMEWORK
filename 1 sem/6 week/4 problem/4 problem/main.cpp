#include "list.h"
#include "readFromFile.h"
#include "mergeSort.h"
#include "test.h"
#include <iostream>

int main()
{
	if (!test())
	{
		std::cout << "Everything is bad";
		return -1;
	}

	List *list = createList();
	readFromFile("file.txt", list);

	std::cout << "Please, choose option:\n\n0 - EXIT\n1 - SORT BY NAME\n2 - SORT BY NUMBER\n3 - PRINT LIST\n\n";
	int userChoice = 0;
	std::cout << "Your choice:   ";
	std::cin >> userChoice;
	std::cout << "\n";

	switch (userChoice)
	{
	case 0:
		break;
	case 1:
		mergeSortRecursive(list, true);
		printList(list);
		break;
	case 2:
		mergeSortRecursive(list, false);
		printList(list);
		break;
	case 3:
		printList(list);
		break;
	default:
		std::cout << "No such option";
		break;
	}
	
	deleteList(list);

	return 0;
}
