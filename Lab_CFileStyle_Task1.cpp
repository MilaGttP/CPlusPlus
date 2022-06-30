
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

void Writing(char* path, char* buff, FILE* file)
{
	if ((file = fopen(path, "w")) == NULL)
		perror("File isn`t opened");
	else
	{
		fprintf(file, "%s", "Words: ");
		char* line = strtok(buff, ",.-_/?!@#");
		while (line != NULL)
		{
			if (strlen(line) >= 7)
			{
				fprintf(file, "%s", line);
				fprintf(file, "%c", line);
			}
			line = strtok(NULL, ",.-_/?!@#");
		}
		fclose(file);
	}
}

char* Reading(char* path, FILE* file)
{
	char* buff = new char[512];
	if ((file = fopen(path, "r")) == NULL)
		perror("File isn`t opened");
	else
	{
		int count = 0;
		while (fgets(buff, 512, file))
			count++;
		cout << count << " lines was read!" << endl;
		fclose(file);
	}
	return buff;
}

int main()
{
	char firstPath[] = "new.txt";
	char secondPath[] = "secondNew.txt";
	FILE* file = NULL;
	char* buff = Reading(firstPath, file);
	Writing(secondPath, buff, file);
	return 0;
}