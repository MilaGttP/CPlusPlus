
#include <iostream>
using namespace std;

class Employer
{
protected:
	string place;
public:
	Employer() { this->place = ""; }
	virtual ~Employer() { this->place.clear(); }
	virtual void Print() = 0;
};

class President : public Employer
{
public:
	President() { this->place = "parliament"; }
	virtual ~President() { this->place.clear(); }
	void Print() override
	{
		cout << "President working place: " << place << endl;
	}
};

class Manager : public Employer
{
public:
	Manager() { this->place = "shop"; }
	virtual ~Manager() { this->place.clear(); }
	void Print() override
	{
		cout << "Manager working place: " << place << endl;
	}
};

class Worker : public Employer
{
public:
	Worker() { this->place = "factory"; }
	virtual ~Worker() { this->place.clear(); }
	void Print() override
	{
		cout << "Worker working place: " << place << endl;
	}
};

int main()
{
	President* president = new President();
	president->Print();

	Manager* manager = new Manager();
	manager->Print();

	Worker* worker = new Worker();
	worker->Print();

	return 0;
}