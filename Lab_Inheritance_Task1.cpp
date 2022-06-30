
#define CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Data
{
protected:
	string name;
	string surname;
	int age;
public:
	void SetName(string value) { this->name = value; }
	void SetSurname(string value) { this->surname = value; }
	void SetAge(int age) { this->age = age; }

	string GetName() { return this->name; }
	string GetSurname() { return this->surname; }
	int GetAge() { return this->age; }
};

class Student : public Data
{
protected:
	uint32_t id;
	string group;
	uint32_t course_number;
	bool isContruct;
public:
	void SetId(uint32_t id) { this->id = id; }
	void SetGroup(string value) { this->group = value; }

	uint32_t GetId() { return this->id; }
	string GetGroup() { return this->group; }

	void Study(string subject)
	{
		cout << "I`m studying a " << subject << endl;
	}
};

class Aspirant : public Student
{
public:
	void WritingDiploma()
	{
		cout << "Writing a diploma!" << endl;
	}
};

int main()
{
	Student student;
	student.SetAge(21);
	cout << "Student`s age: " << student.GetAge() << endl;
	student.SetName("Ivan");
	cout << "Student`s name: " << student.GetName() << endl;
	student.Study("math");

	Aspirant aspirant;
	aspirant.SetAge(21);
	cout << "Aspirant`s age: " << aspirant.GetAge() << endl;
	aspirant.SetId(5);
	cout << "Aspirant`s id: " << aspirant.GetId() << endl;
	aspirant.WritingDiploma();

	return 0;
}