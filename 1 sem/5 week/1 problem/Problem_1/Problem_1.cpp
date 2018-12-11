#include <string>
#include <iostream>
#include "listFunctions.h"
#include "test.h"

using namespace std;

void interactive(List &list)
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
				int value = 0;
				cin >> value;
				addElement(list, value);
				cout << endl; 
			}
			break;
		case 2: 
			{
				int elementToDelete = 0;
				cin >> elementToDelete;
				whatToDelete(list, elementToDelete); 
				cout << endl;
			}
			break;
		case 3:
			printList(list);
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

int main()
{
	if(!test())
	{
		cout << "Everything is bad ;(";
		return 1;
	}
	else 
	{
		List list;
		cout << "0 - EXIT\n1 - ADD ELEMENT\n2 - DELETE ELEMENT\n3 - PRINT LIST\n4 - CLEAR SCREEN\n\n";
		interactive(list);
		deleteList(list);
	}
	return 0;
}
