
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <conio.h>

#include "String.h"

using namespace std;

int String::counter{ 0 };

String::String()
{
	str = new char[80 + 1];
	id = ++counter;
}

String::String(const int len) :String()
{
	str = new char[len + 1];
}

String::String(const char* string) :String()
{
	str = new char[strlen(string) + 1];
	strcpy(str, string);
}

String::~String()
{
	delete[] str;
}

void String::SetName(const char* value)
{
	delete[] str;
	str = new char[strlen(value) + 1];
	strcpy(str, value);
}

void String::Input() const
{
	delete[] str;
	char buff[128]{ 0 };
	cout << "Enter your string: ";
	cin.getline(buff, sizeof(buff));
	strcpy(str, buff);
}

void String::Out(const char* prompt) const
{
	cout << prompt << ":\t" << id << " "
		<< (GetName() == nullptr ? "" : GetName()) << endl;
}
