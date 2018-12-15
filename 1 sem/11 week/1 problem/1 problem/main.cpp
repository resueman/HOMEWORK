#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefixFunction(const string &str)
{
	const int size = str.length();
	vector <int> prefix(size); //vector of max own prefixs, which equal to suffix 
	prefix[0] = 0;
	int numberOfSufEqualPref = 0;
	for (int i = 1; i < size; ++i)
	{
		while (numberOfSufEqualPref > 0 && str[i] != str[numberOfSufEqualPref])
		{
			numberOfSufEqualPref = prefix[numberOfSufEqualPref - 1];
		}
		if (str[i] == str[numberOfSufEqualPref])
		{
			++numberOfSufEqualPref;
		}
		prefix[i] = numberOfSufEqualPref;
	}
	return prefix;
}

int search(const string &str, const string &subStr)
{
	if (str.length() < subStr.length() || str == "" || subStr == "")
	{
		return -2;
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
	return -1;
}

int main()
{
	cout << "Enter string:   ";
	string str = "";
	cin >> str;
	cout << "Enter substring:   ";
	string subStr = "";
	cin >> subStr;
	cout << search(str, subStr);
	
	return 0;
}