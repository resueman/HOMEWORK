#include "interaction.h"
#include "print.h"
#include <iostream>

using namespace std;

void printOptions()
{
	cout << "Please, choose option:\n0 - EXIT\n1 - ADD ELEMENT\n2 - DELETE ELEMENT\n3 - CHECK EXISTENCE\n";
	cout << "4 - PRINT IN ASCENDING ORDER\n5 - PRINT IN DESCENDING ORDER\n6 - CLEAR SCREEN";
}

void case1(Set* set)
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

void case2(Set* set)
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

void case3(Set* set)
{
	cout << "Check existence of:   ";
	int numberToCheck = 0;
	cin >> numberToCheck;
	if (exists(set, numberToCheck))
	{
		cout << "Exists";
	}
	else
	{
		cout << "No such element in a set";
	}
}

void interaction()
{
	printOptions();
	Set *set = createSet();
	int userChoice = 0;
	do
	{
		cout << "\n\nYour choice:   ";
		cin >> userChoice;
		switch (userChoice)
		{
		case 0:
			break;
		case 1:
			case1(set);
			break;
		case 2:
			case2(set);
			break;
		case 3:
			case3(set);
			break;
		case 4:
		{
			std::string str = "";
			printAscendingOrder(set, set->root, str);
			cout << str;
		}
		break;
		case 5:
		{
			std::string str = "";
			printDescendingOrder(set, set->root, str);
			cout << str;
		}
		break;
		case 6:
			system("cls");
			printOptions();
			break;
		default:
			cout << "No such option";
			break;
		}
	} while (userChoice != 0);
}
