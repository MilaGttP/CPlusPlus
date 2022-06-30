
#include <iostream>
using namespace std;

class Pet
{
protected:
	string name;
	string description;
public:
	Pet() = default;
	~Pet() = default;
	Pet(string name) { this->name = name; }
	Pet(string name, string description) 
	{ 
		this->name = name;
		this->description = description;
	}
	virtual void Show() = 0;
};

class Dog : public Pet
{
public:
	Dog()
	{
		this->name = "Sharik";
		this->description = "Has big ears";
	}
	Dog(string name, string description) : Pet (name, description) {}
	void Show() override
	{
		cout << endl << "Dog`s name: " << this->name << endl
			<< "Dog`s description: " << this->description << endl;
	}
};

class Cat : public Pet
{
public:
	Cat()
	{
		this->name = "Murchik";
		this->description = "Has fluffy wool";
	}
	Cat(string name, string description) : Pet(name, description) {}
	void Show() override
	{
		cout << endl << "Cat`s name: " << this->name << endl
			<< "Cat`s description: " << this->description << endl;
	}
};

class Parrot : public Pet
{
public:
	Parrot()
	{
		this->name = "Kesha";
		this->description = "Has orange wings";
	}
	Parrot(string name, string description) : Pet(name, description) {}
	void Show() override
	{
		cout << endl << "Parrot`s name: " << this->name << endl
			<< "Parrot`s description: " << this->description << endl;
	}
};

int main()
{
	Dog dog;
	dog.Show();

	Cat cat;
	cat.Show();

	Parrot parrot;
	parrot.Show();

	return 0;
}