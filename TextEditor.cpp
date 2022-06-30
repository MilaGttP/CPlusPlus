
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
using namespace std;

class TextEditor
{
protected:
	string fileName;
	string fileNameExe;
	fstream file;
	string buff;
	uint32_t count;
public:
	TextEditor()
	{
		this->fileName = "Test.cpp"; this->fileNameExe = "Prog.exe";
		this->buff = ""; this->count = 1;
	}
	~TextEditor() = default;
	void RunCopying(string pathFrom, string pathTo)
	{
		fstream from; fstream to;
		from.open(pathFrom, ios::in);
		if (from.is_open())
		{
			to.open(pathTo, ios::out | ios::app);
			if (to.is_open())
			{
				cout << "\nText, which we will copy: \n";
				while (getline(from, this->buff))
				{
					cout << buff << endl; //for check
					to << this->buff << endl;
				}
				from.close();
				to.close();
			}
			else
				perror("FileTo: Erorr! File isn`t opened");
		}
		else
			perror("FileFrom: Erorr! File isn`t opened");
	}
	void RunAppendingAndEditing()
	{
		cout << endl;
		this->file.open(this->fileName, ios::out | ios::app);
		if (this->file.is_open())
		{
			while (true)
			{
				cout << right << setfill(' ') << setw(8) << this->count << "| ";
				getline(cin, buff);
				if (this->buff[0] == '0')
				{
					cout << "Compiled!" << endl;
					break;
				}
				else
				{
					this->file << this->buff << endl;
					this->count++;
				}
			}
			this->file.close();
			string commandCompile = "g++ -o " + this->fileNameExe + " " + this->fileName;
			string commandRun = "start " + this->fileNameExe;
			system(commandCompile.c_str());
			system(commandRun.c_str());
		}
		else
			cout << "Erorr! File isn`t opened" << endl;
	}
	void RunRewriting()
	{
		fstream stream; string tmp;
		stream.open(fileName, ios::in);
		if (stream.is_open())
		{
			cout << "\nPrevious text is: \n";
			while (getline(stream, tmp))
				cout << tmp << endl;
			file.close();
		}
		else
			cout << "Erorr! File isn`t opened" << endl;

		cout << endl;
		this->file.open(this->fileName, ios::out | ios::app);
		if (this->file.is_open())
		{
			while (true)
			{
				cout << right << setfill(' ') << setw(8) << this->count << "| ";
				getline(cin, buff);
				if (this->buff[0] == '0')
				{
					cout << "Wrote!" << endl;
					break;
				}
				else
				{
					this->file << this->buff << endl;
					this->count++;
				}
			}
			this->file.close();
		}
		else
			cout << "Erorr! File isn`t opened" << endl;
	}
};

int main()
{
	TextEditor textEditor;
	textEditor.RunCopying("from.txt", "to.txt");
	textEditor.RunAppendingAndEditing();
	textEditor.RunRewriting();

	return 0;
}