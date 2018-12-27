#include "listFunctions.h"
#include "test.h"

#include <iostream>

using namespace std;

void interactive(List *list)
{
	int userChoice = 0;
	do
	{	
		cout << "Choose option, please\n";
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
			cout << "0 - EXIT\n";
			cout << "1 - ADD ELEMENT\n";
			cout << "2 - DELETE ELEMENT\n";
			cout << "3 - PRINT LIST\n";
			cout << "4 - CLEAR SCREEN\n\n";
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
	List* list = createList();
	cout << "0 - EXIT\n";
	cout << "1 - ADD ELEMENT\n";
	cout << "2 - DELETE ELEMENT\n";
	cout << "3 - PRINT LIST\n";
	cout << "4 - CLEAR SCREEN\n\n";
	interactive(list);
	deleteList(list);
	
	return 0;
}
