#pragma once

struct Person
{
	char name[20];
	char telephoneNumber[20];
}man[100]{};

void addRecord(int* numberOfRecords)//1
{
	printf(" Enter name:   ");
	scanf("%s", &man[*numberOfRecords].name);
	printf(" Enter telephone number:   ");
	scanf("%s", &man[*numberOfRecords].telephoneNumber);
	(*numberOfRecords)++;
}

void printAllRecords(int numberOfRecords, Person* man)//2
{
	if (numberOfRecords == 0)
	{
		printf(" Phonebook is empty\n\n");
	}
	else 
	{
		for (int i = 0; i < numberOfRecords; ++i)
		{
			printf(" %s   %s\n", man[i].name, man[i].telephoneNumber);
		}
	}
}

void findNumber(Person* man, int numberOfRecords, char* ownerOfTelephoneNumber)//3
{
	int i = 0;
	while ((i < numberOfRecords) && (strcmp(man[i].name, ownerOfTelephoneNumber) != 0))
	{
		i++;
	}
	i != numberOfRecords ? printf(" Result:   %s\n\n", man[i].telephoneNumber)
		: printf(" There is no %s's telephone number in base\n\n", ownerOfTelephoneNumber);
}

void findName(Person *man, int numberOfRecords, char* smbTelephoneNumber)//4
{
	int i = 0;
	while ((i < numberOfRecords) && (strcmp(man[i].telephoneNumber, smbTelephoneNumber) != 0))
	{
		i++;
	}
	i != numberOfRecords ? printf(" Result:   %s\n\n", man[i].name)
		: printf(" Owner of %s not found\n\n", smbTelephoneNumber);
}

void saveToFile(int currentNumberOfRecords)//5
{
	FILE * out = fopen("file.txt", "w");
	for (int i = 0; i < currentNumberOfRecords; i++)
	{
		fprintf(out, "%s   %s\n", man[i].name, man[i].telephoneNumber);
	}
	printf(" Changes saved\n");
	fclose(out);
}
