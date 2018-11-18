#include "tree.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Please, choose option:\n0 - EXIT\n1 - ADD ELEMENT\n2 - DELETE ELEMENT\n3 - CHECK EXISTENCE\n";
	cout << "4 - PRINT IN ASCENDING ORDER\n5 - PRINT IN DESCENDING ORDER\n";
	int userChoice = 0;
	std::cin >> userChoice;
	Set *set = createSet();
	switch (userChoice)
	{
	case 0:
		break;
	case 1:
	{
		cout << "Element to add:   ";
		int numberToAdd = 0;
		cin >> numberToAdd;
		if (addToSet(set, numberToAdd))
		{
			cout << "Element successfully added";
		}
		else
		{
			cout << "Such element already exists";
		}
	}
	break;
	case 2:
	{
		cout << "Element to delete:   ";
		int numberToDelete = 0;
		cin >> numberToDelete;
		if (removeFromSet(set, numberToDelete))
		{
			cout << "Element successfully deleted";
		}
		else
		{
			cout << "No such element in a set";
		}
	}
	break;
	case 3:
	{
		cout << "Enter the value of the element to be checked for existence";
		int numberToCheck = 0;
		cin >> numberToCheck;
		if (exists(set, numberToCheck))
		{
			cout << "Existd";
		}
		else
		{
			cout << "No such element in a set";
		}
	}
	break;
	case 4:

		break;
	case 5:

		break;
	default:
		std::cout << "No such option";
		break;
	}
}
