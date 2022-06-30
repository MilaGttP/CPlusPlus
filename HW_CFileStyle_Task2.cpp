
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
using namespace std;

class Statistics
{
protected:
	FILE* fileFrom;
	char buff[1024];
	char* CONSONANTS;
	char* VOWELS;
	char* NUMBERS;
	int symbols = 0;
	int str = 0;
	int consonants = 0;
	int vowels = 0;
	int numbers = 0;
public:
	Statistics()
	{
		this->CONSONANTS == "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
		this->VOWELS == "AEIOUaeiou";
		this->NUMBERS == "1234567890";
		this->fileFrom = nullptr;
	}
	int SymbolsQuantity(const char pathFrom[])
	{
		int symbol = 0;
		if ((this->fileFrom = fopen(pathFrom, "r")) == NULL)
		{
			perror("Error of opening file!");
			return 0;
		}
		else
		{
			while (fgets(this->buff, 1024, this->fileFrom))
			{
				const char* ch = nullptr;
				fputs(ch, this->fileFrom);
				symbol++;
			}
		}
		fclose(this->fileFrom);
		return symbol - 1;
	}
	int StrQuantity(const char pathFrom[])
	{
		int str = 0;
		if ((this->fileFrom = fopen(pathFrom, "r")) == NULL)
		{
			perror("Error of opening file!");
			return 0;
		}
		else
		{
			while (fgets(this->buff, 1024, this->fileFrom))
				str++;
		}
		fclose(this->fileFrom);
		return this->str;
	}
	int ConsonantsQuantity(const char pathFrom[])
	{
		int consonants = 0;
		if ((this->fileFrom = fopen(pathFrom, "r")) == NULL)
		{
			perror("Error of opening file!");
			return 0;
		}
		else
		{
			while (fgets(this->buff, 1024, this->fileFrom))
			{
				if (strcmp(buff, CONSONANTS) == 0)
					this->consonants++;
			}
		}
		fclose(this->fileFrom);
		return this->consonants;
	}
	int VowelsQuantity(const char pathFrom[])
	{
		int vowels = 0;
		if ((this->fileFrom = fopen(pathFrom, "r")) == NULL)
		{
			perror("Error of opening file!");
			return 0;
		}
		else
		{
			while (fgets(this->buff, 1024, this->fileFrom))
			{
				if (strcmp(buff, VOWELS) == 0)
					this->vowels++;
			}
		}
		fclose(this->fileFrom);
		return this->vowels;
	}
	int NumbersQuantity(const char pathFrom[])
	{
		int numbers = 0;
		if ((this->fileFrom = fopen(pathFrom, "r")) == NULL)
		{
			perror("Error of opening file!");
			return 0;
		}
		else
		{
			while (fgets(this->buff, 1024, this->fileFrom))
			{
				if (strcmp(buff, NUMBERS) == 0)
					this->numbers++;
			}
		}
		fclose(this->fileFrom);
		return this->numbers;
	}

	void ToConsole(const char pathFrom[])
	{
		cout << "Quantity of symbols: " << this->SymbolsQuantity(pathFrom) << endl;
		cout << "Quantity of str: " << this->StrQuantity(pathFrom) << endl;
		cout << "Quantity of consonants: " << this->ConsonantsQuantity(pathFrom) << endl;
		cout << "Quantity of vowels: " << this->VowelsQuantity(pathFrom) << endl;
		cout << "Quantity of numbers: " << this->NumbersQuantity(pathFrom) << endl;
	}
	void ToFile(const char pathTo[])
	{
		FILE* fileTo; char buff[1024];
		if ((fileTo = fopen(pathTo, "w")) == NULL)
		{
			perror("Error of opening file!");
		}
		else
		{
			while (fgets(buff, 1024, fileTo))
			{
				fputc(symbols, fileTo);
				fputc(str, fileTo);
				fputc(consonants, fileTo);
				fputc(vowels, fileTo);
				fputc(numbers, fileTo);
			}
		}
		fclose(fileTo);
	}
};

int main()
{
	Statistics stat;
	stat.ToConsole("from.txt");
	stat.ToFile("to.txt");
	return 0;
}