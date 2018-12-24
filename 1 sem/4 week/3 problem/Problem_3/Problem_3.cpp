#define _CRT_SECURE_NO_WARNINGS 

#include "functionsForPhonebook.h"

void interaction(int numberOfRecords, Person *man)
{
	int userChoice = -1;
	do
	{
		printf("\n\n");
		printf(" Choose option, please \n");
		printf(" Your choice: ");
		scanf("%d", &userChoice);
		switch (userChoice)
		{
		case 0:
			return;
		case 1:///add record
			addRecord(numberOfRecords, man);
			break;
		case 2:///print
			printAllRecords(numberOfRecords, man);
			break;
		case 3:///find number
		{
			char ownerOfTelephoneNumber[20];
			printf(" Let's find telephone number, which belongs to :   ");
			scanf("%s", &ownerOfTelephoneNumber);
			printf(" %s", findNumber(man, numberOfRecords, ownerOfTelephoneNumber).c_str());
		}
		break;
		case 4:///find name
		{
			char smbTelephoneNumber[20];
			printf(" Enter telephone number:   ");
			scanf("%s", &smbTelephoneNumber);
			findName(man, numberOfRecords, smbTelephoneNumber);
			printf(" %s", findName(man, numberOfRecords, smbTelephoneNumber).c_str());
		}
		break;
		case 5:///save
			saveToFile(numberOfRecords, man);
			break;
		default:
			printf(" No such option ;(");
			break;
		}
	} while (userChoice != 0);
}

int readFromFile(const char *fileName, Person* man)
{
	FILE *currentFile = fopen(fileName, "r");
	int numberOfRecords = 0;
	if (!currentFile)
	{
		printf(" File not found!\n\n");
		return -2;
	}
	while (!feof(currentFile) && (numberOfRecords < baseSize))
	{
		const int readBytes = fscanf(currentFile, "%s%s", &man[numberOfRecords].name, &man[numberOfRecords].telephoneNumber);
		if (readBytes < 0)
		{
			break;
		}
		numberOfRecords++;
	}
	fclose(currentFile);
	return numberOfRecords;
}

bool test()
{
	Person personTest[10]{};
	readFromFile("test.txt", personTest);
	return (findName(personTest, 6, personTest[0].telephoneNumber) == "qwerty") && 
		(findName(personTest, 6, personTest[3].telephoneNumber) == "qwe") &&
			(findName(personTest, 6, personTest[5].telephoneNumber) == "q") &&
				(findNumber(personTest, 6, personTest[0].name) == "123456") &&
					(findNumber(personTest, 6, personTest[3].name) == "123") &&
						(findNumber(personTest, 6, personTest[5].name) == "1");
}

int main()
{
	if (!test())
	{
		printf("Program doesn't work ;(");
		return 1;
	}
	system("cls");
	printf(" 0. Exit\n");
	printf(" 1. Add record\n");
	printf(" 2. Print all records\n");
	printf(" 3. Find number\n");
	printf(" 4. Find name\n");
	printf(" 5. Save current data to file\n");

	Person man[baseSize]{};
	interaction(readFromFile("file.txt", man), man);
	return 0;
}
