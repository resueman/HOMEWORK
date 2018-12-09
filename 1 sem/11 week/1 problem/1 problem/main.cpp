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
		while (numberOfSufEqualPref > 0 && prefix[i] != prefix[numberOfSufEqualPref])
		{
			numberOfSufEqualPref = prefix[numberOfSufEqualPref - 1];
		}
		if (prefix[i] == prefix[numberOfSufEqualPref])
		{
			++numberOfSufEqualPref;
		}
		prefix[i] = numberOfSufEqualPref;
	}
	return prefix;
}

int search(const string &str, const string &subStr)
{
	int result = -1;
	vector<int> prefix = prefixFunction(str);

	return result;
}

int main()
{
	cout << "Enter string:   ";
	cout << "Enter substring:   ";
	string str = "";
	cin >> str;
	string subStr = "";
	cin >> subStr;


	return 0;
}