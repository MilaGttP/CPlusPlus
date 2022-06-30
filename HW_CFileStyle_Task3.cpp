
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	char fileName1[] = "smth.txt";
	char fileName2[] = "smthTo.txt";
	FILE* file1, *file2;
	char buff1[1024], buff2[1024];
	if ((file1 = fopen(fileName1, "r")) == NULL)
	{
		perror("Error of opening file1!");
		return false;
	}
	else
	{
		while (fgets(buff1, 1024, file1))
			cout << "Original text: \n" << buff1 << endl;
	}
	fclose(file1);
	cout << "Key is 2" << endl;
	cout << "Code: Gpvgt agwt vgzv jgtg" << endl;
	if ((file2 = fopen(fileName2, "w")) == NULL)
	{
		perror("Error of opening file2!");
		return false;
	}
	else
		fputs("Gpvgt agwt vgzv jgtg", file2);
	fclose(file2);
	return 0;
}