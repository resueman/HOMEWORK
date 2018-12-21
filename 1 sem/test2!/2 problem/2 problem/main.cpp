#include "list.h"
#include <iostream>

using namespace std;

void interactive()
{
	List* list = createList();

	int userChoice = 0;
	do
	{
		cout << "Choose option, please \n";
		cout << "Your choice: ";
		cin >> userChoice;
		switch (userChoice)
		{
		case 0:
			return;
		case 1:
		{
			cout << "Enter value:  ";
			int value = 0;
			cin >> value;
			cout << "Enter position(add):  ";
			int position = 0;
			cin >> position;
			addNode(list, value, position);
			cout << endl;
		}
		break;
		case 2:
		{
			cout << "Enter position(delete):  ";
			int position = 0;
			cin >> position;
			deleteNode(list, position);
			cout << endl;
		}
		break;
		case 3:
			cout << printList(list);
			break;
		case 4:
			system("cls");
			cout << "0 - EXIT\n1 - ADD ELEMENT\n2 - DELETE ELEMENT\n3 - PRINT LIST\n4 - CLEAR SCREEN\n\n";
			break;
		default:
			cout << "No such option ;(\n";
			break;
		}
	} while (userChoice != 0);

	deleteList(list);
}

bool test()
{
	List* testList = createList();
	addNode(testList, 4, 1);
	addNode(testList, 5, 0);
	addNode(testList, 7, 2);
	addNode(testList, 6, 1);
	addNode(testList, 1, 3);
	addNode(testList, 3, 5);

	bool result1 = printList(testList) == "6 4 1 7 5 ";
	if (!result1)
	{
		cout << "test 1 not passed\n";
		deleteList(testList);
		return false;
	}

	deleteNode(testList, 5);
	deleteNode(testList, 1);
	deleteNode(testList, 2);
	deleteNode(testList, 0);

	bool result2 = printList(testList) == "4 7 ";
	if (!result2)
	{
		cout << "test 2 not passed\n";
		deleteList(testList);
		return false;
	}

	deleteNode(testList, 1);
	deleteNode(testList, 1);
	bool result3 = printList(testList) == "No elements in list\n";
	if (!result2)
	{
		cout << "test 3 not passed\n";
		deleteList(testList);
		return false;
	}

	cout << "All tests passed";
	deleteList(testList);
	return true;
}

int main()
{
	if (!test())
	{
		cout << ";(";
		return -1;
	}
	system("cls");
	interactive();

	return 0;
}