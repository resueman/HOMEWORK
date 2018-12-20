#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <istream>

using namespace std;

vector<int> prefixFunction(const string &str)
{
	const int size = str.length();
	vector<int> prefix(size); //vector of max own prefixs, which equal to suffix 
	prefix[0] = 0;
	int numberOfSuffixiesEqualToPrefixies = 0;
	for (int i = 1; i < size; ++i)
	{
		while (numberOfSuffixiesEqualToPrefixies > 0 && str[i] != str[numberOfSuffixiesEqualToPrefixies])
		{
			numberOfSuffixiesEqualToPrefixies = prefix[numberOfSuffixiesEqualToPrefixies - 1];
		}
		if (str[i] == str[numberOfSuffixiesEqualToPrefixies])
		{
			++numberOfSuffixiesEqualToPrefixies;
		}
		prefix[i] = numberOfSuffixiesEqualToPrefixies;
	}
	return prefix;
}

int search(const string &str, const string &subStr)
{
	if (str.length() < subStr.length() || str == "" || subStr == "")
	{
		cout << "Incorrect input\n";
		return 0;
	}

	vector<int> prefix = prefixFunction(subStr);
	int i = 0;
	int j = 0;
	
	while (i < str.length())
	{
		if (str[i] == subStr[j])
		{
			++i;
			++j;
			if (j == subStr.length())
			{
				cout << i - j + 1 << endl;
				return i - j + 1;
			} 
		}
		else
		{
			if (j != 0)
			{
				j = prefix[j - 1];
				
			}
			else
			{
				i++;
			}
		}
	}
	cout << "No entries\n";

	return 0;
}

string readFromFile(const char* fileName)
{
	ifstream file;
	file.open(fileName);
	string str = "";
	if (!file.is_open())
	{
		return "";
	}
	while (!file.eof())
	{
		file >> str;
	}
	file.close();

	return str;
}

bool test()
{
	string str1 = "";
	string subStr1 = "";//-2

	string str2 = "aababaabbaabaab";
	string subStr2 = "aabaa"; //10

	string str3 = "abbabba";
	string subStr3 = "abbabbabb";//-2
	
	string str4 = "abbabbabbac";
	string subStr4 = "abbb";//-1
	
	string str5 = "abcabeabcabcabd";
	string subStr5 = "abcabd";//10

	string str6 = "aabaabbaaabaabaabaabaabaabbc";
	string subStr6 = "aabbc";//21

	string str7 = "abcdefghhop";
	string subStr7 = "fgh";//6

	bool result = search(str1, subStr1) == 0 && search(str2, subStr2) == 10 &&
		search(str3, subStr3) == 0 && search(str4, subStr4) == 0 &&
		search(str5, subStr5) == 10 && search(str6, subStr6) == 24 && search(str7, subStr7) == 6;
	
	system("cls");

	return result;
}

int main()
{
	if (!test())
	{
		cout << ":(";
		return 1;
	}
	string str = readFromFile("file.txt");
	cout << "Enter string:   ";
	string subStr = "";
	cin >> subStr;

	search(str, subStr);
	
	return 0;
}
