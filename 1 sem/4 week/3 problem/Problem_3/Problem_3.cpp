#define _CRT_SECURE_NO_WARNINGS 

#include "functionsForPhonebook.h"

void interaction(int numberOfRecords, Person *man)
{
	int userChoice = -1;
	do
	{
		printf("\n");
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
			std::cout << " " << findNumber(man, numberOfRecords, ownerOfTelephoneNumber) << "\n";//this works
			//printf(" %s", findNumber(man, numberOfRecords, ownerOfTelephoneNumber));//doesn't work, print smth strange???
		}
		break;
		case 4:///find name
		{
			char smbTelephoneNumber[20];
			printf(" Enter telephone number:   ");
			scanf("%s", &smbTelephoneNumber);
			findName(man, numberOfRecords, smbTelephoneNumber);
			std::cout << " " << findName(man, numberOfRecords, smbTelephoneNumber) << "\n";//this works
			//printf(" %s", findName(man, numberOfRecords, smbTelephoneNumber));//doesn't work, print smth strange
		}
		break;
		case 5:///save
			saveToFile(numberOfRecords, man);
			break;
		default:
			printf(" No such option ;(\n");
			break;
		}
	} while (userChoice != 0);
}

int readFromFile(FILE *file, Person* man)
{
	int numberOfRecords = 0;
	if (!file)
	{
		printf(" File not found!\n\n");
	}
	else
	{
		while (!feof(file)&&(numberOfRecords < baseSize))
		{
			const int readBytes = fscanf(file, "%s%s", &man[numberOfRecords].name, &man[numberOfRecords].telephoneNumber);
			if (readBytes < 0)
			{
				break;
			}
			numberOfRecords++;
		}
		fclose(file);
	}
	return numberOfRecords;
}

bool test()
{
	Person personTest[10]{};
	FILE *test = fopen("test.txt", "r");
	readFromFile(test, personTest);
	return (findName(personTest, 6, personTest[0].telephoneNumber) == "qwerty") * 
		(findName(personTest, 6, personTest[3].telephoneNumber) == "qwe") *
			(findName(personTest, 6, personTest[5].telephoneNumber) == "q") *
				(findNumber(personTest, 6, personTest[0].name) == "123456") *
					(findNumber(personTest, 6, personTest[3].name) == "123") *
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
	FILE *file = fopen("file.txt", "r");
	interaction(readFromFile(file, man), man);
	return 0;
}
