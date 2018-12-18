#include <string>
#include <iostream>
#include "list.h"
//#include "test.h"

using namespace std;

void interactive(List *list)
{
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
			addElement(list, value, position);
			cout << endl;
		}
		break;
		case 2:
		{
			cout << "Enter position(delete):  ";
			int position = 0;
			cin >> position;
			deleteElement(list, position);
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
}

bool test()
{
	List* listTest = createList();
	addElement(listTest, 4, 1);
	addElement(listTest, 5, 0);
	addElement(listTest, 7, 2);
	addElement(listTest, 6, 1);
	addElement(listTest, 1, 3);
	addElement(listTest, 3, 5);

	bool result1 = printList(listTest) == "5 6 4 1 7 3 ";
	if (!result1)
	{
		cout << "test 1 not passed\n";
		deleteList(listTest);
		return false;
	}

	deleteElement(listTest, 5);
	deleteElement(listTest, 1);
	deleteElement(listTest, 2);
	deleteElement(listTest, 0);
	
	bool result2 = printList(listTest) == "4 7 ";
	if (!result2)
	{
		cout << "test 2 not passed\n";
		deleteList(listTest);
		return false;
	}

	deleteElement(listTest, 0);
	deleteElement(listTest, 0);
	bool result3 = printList(listTest) == "No elements in list\n";
	if (!result2)
	{
		cout << "test 3 not passed\n";
		deleteList(listTest);
		return false;
	}

	cout << "All tests passed";
	deleteList(listTest);
	return true;
}

int main()
{
	if (!test())
	{
		cout << "Everything is bad ;(";
		return 1;
	}
	
	List* list = createList();
	cout << "0 - EXIT\n1 - ADD ELEMENT\n2 - DELETE ELEMENT\n3 - PRINT LIST\n4 - CLEAR SCREEN\n\n";
	interactive(list);
	deleteList(list);
	
	return 0;
}
