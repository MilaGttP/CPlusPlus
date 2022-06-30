
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
using namespace std;

bool FromFileToFile(char pathFrom[], char pathTo[])
{
	FILE* fileFrom, * fileTo;
	char buff[1024];
	if ((fileFrom = fopen(pathFrom, "r")) == NULL)
	{
		perror("Error of opening file!");
		return false;
	}
	if ((fileTo = fopen(pathTo, "w")) == NULL)
	{
		perror("Error of opening file!");
		return false;
	}
	while (fgets(buff, 1024, fileFrom))
	{
		_strrev(buff);
		fputs(buff, fileTo);
	}
	fclose(fileFrom);
	fclose(fileTo);
	return true;
}

int main()
{
	char pathFrom[] = "file1.txt";
	char pathTo[] = "file2.txt";
	FromFileToFile(pathFrom, pathTo);
	return 0;
}