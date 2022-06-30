
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
using namespace std;

bool FromFileToFile(char pathFrom[], char pathTo[])
{
	FILE * fileFrom, *fileTo;
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
		fputs(buff, fileTo);
	fclose(fileFrom);
	fclose(fileTo);
	return true;
}

int main()
{
	char pathFrom[] = "smth.txt";
	char pathTo[] = "secondSmth.txt";
	FromFileToFile(pathFrom, pathTo);
	return 0;
}