
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
using namespace std;

bool Comparison(char path1[], char path2[])
{
	FILE* file1, *file2;
	char buff1[1024], buff2[1024];
	if ((file1 = fopen(path1, "r")) == NULL)
	{
		perror("Error of opening file!");
		return false;
	}
	if ((file2 = fopen(path2, "r")) == NULL)
	{
		perror("Error of opening file!");
		return false;
	}
	while (fgets(buff1, 1024, file1))
	{
		while (fgets(buff2, 1024, file2))
		{
			if (strcmp(buff1, buff2) != 0)
			{
				puts("Strcmp: Strings aren`t equal: \n");
				puts(buff1);
				puts(buff2);
				break;
			}
			else if (strlen(buff1) != strlen(buff2))
			{
				puts("Strlen: Strings aren`t equal: \n");
				puts(buff1);
				puts(buff2);
				break;
			}
			else
				puts("Strings are equal!");
		}
	}
	fclose(file1);
	fclose(file2);
	return true;
}

int main()
{
	char path1[] = "smth.txt";
	char path2[] = "secondSmth.txt";
	Comparison(path1, path2);
	return 0;
}