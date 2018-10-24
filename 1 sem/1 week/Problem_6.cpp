#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int k = 0;
	string s, s1;

	printf("%s", "Enter S  =  ");
	scanf("%s", &s);
	//cin >> s;
	printf("%s", "Enter S1  =  ");
	scanf("%s", &s1);
	//cin >> s1;
/*
	int i = 0;
	while (i < ns) {

		if (s[i] == s1[0]) {
			int j = 1;
			int ii = i + 1;
			while ((j < ns1) && (s[i] == s1[j])) {
				i++;
				j++;
			}
			if (j == ns1) k++;
		}
			
	}
	
	printf("%d", k);*/
	_getch();
	return 0;
}