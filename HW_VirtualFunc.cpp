#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Base
{
public:
	virtual void Display(string path)
	{
		/*cout << "Enter the name of file: ";
		cin >> path;*/
		ifstream fin; 
		fin.open(path);
		if (!fin.is_open())
			cout << "File opening error! " << endl;
		else
		{
			string str;
			cout << endl << "File opened! \n" << "Text: " << endl;
			while (!fin.eof())
			{
				str = " ";
				getline(fin, str);
				cout << str << endl;
			}
		}
		fin.close();
		cout << endl;
	}
};

class ASCII : virtual public Base
{
public:
	void Display(string path) override
	{
		ifstream fin; char buff[256];
		fin.open(path);
		if (!fin.is_open())
			cout << "File opening error! " << endl;
		else
		{
			cout << "File opened! \n" << "ASCII text: " << endl;
			while (!fin.eof())
			{
				fin.getline(buff, sizeof(buff));
				cout << buff << endl;
			}
		}
		fin.close();
		cout << endl;
	}
};

class Binary : virtual public Base
{
public:
	void Display(string path) override
	{
		ifstream fin; char buff[256];
		fin.open(path);
		if (!fin.is_open())
			cout << "File opening error! " << endl;
		else
		{
			cout << "File opened! \n" << "Binary text: " << endl;
			while (!fin.eof())
			{
				fin.getline(buff, sizeof(buff));
				cout << buff << endl;
			}
		}
		fin.close();
		cout << endl;
	}
};

int main()
{
	Base base;
	base.Display("ForText.txt");

	ASCII ascii;
	ascii.Display("ForASCII.txt");

	Binary binary;
	binary.Display("ForBinary.txt");
	binary.Display("ForBinary.bin");

	return 0;
}