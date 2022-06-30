
#include <iostream>
using namespace std;

class Passport
{
protected:
	int id;
	string fullName;
	string nation;
	int age;
public:
	void SetId(int id) { this->id = id; }
	void SetFullName(string value) { this->fullName = value; }
	void SetNation(string value) { this->nation = value; }
	void SetAge(int age) { this->age = age; }

	int GetId() { return this->id; }
	string GetFullName() { return this->fullName; }
	string GetNation() { return this->nation; }
	int GetAge() { return this->age; }
};

class ForeignPassport : public Passport
{
protected:
	int foreignId;
	string visa;
public:
	void SetForeignId(int id) { this->foreignId = id; }
	void SetVisa(string value) { this->visa = value; }

	int GetForeignId() { return this->foreignId; }
	string GetVisa() { return this->visa; }
};

int main()
{
	Passport pass;
	pass.SetId(1344255); pass.SetNation("Ukrainian");
	cout << "Ukr pass id: " << pass.GetId() << "\n"
		<< "Ukr pass nation: " << pass.GetNation() << endl;

	ForeignPassport fPass;
	fPass.SetId(4646423412); fPass.SetAge(34);
	cout << "Foreign pass id: " << fPass.GetId() << "\n"
		<< "Foreign pass age: " << fPass.GetAge() << endl;

	return 0;
}