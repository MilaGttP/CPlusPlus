#include <iostream>
using namespace std;

class Pets
{
protected:
	string name;
	string type;
public:
	virtual void Show() = 0;
	virtual void Type() = 0;
	virtual void Sound() = 0;
};

class Dog : virtual public Pets
{
public:
	Dog()
	{
		this->name = "Bonya";
		this->type = "Dog";
	}
	void Show() override
	{
		cout << "\n --- Info --- " << endl;
		cout << " Name: " << this->name << endl;
	}
	void Type() override
	{
		cout << " Type: " << this->type << endl;
	}
	void Sound() override
	{
		cout << " Sound: " << "gav - gav" << endl;
	}
};

class Cat : virtual public Pets
{
public:
	Cat()
	{
		this->name = "Murzik";
		this->type = "Cat";
	}
	void Show() override
	{
		cout << "\n --- Info --- " << endl;
		cout << " Name: " << this->name << endl;
	}
	void Type() override
	{
		cout << " Type: " << this->type << endl;
	}
	void Sound() override
	{
		cout << " Sound: " << "mew - mew" << endl;
	}
};

class Parrot : virtual public Pets
{
public:
	Parrot()
	{
		this->name = "Kesha";
		this->type = "Parrot";
	}
	void Show() override
	{
		cout << "\n --- Info --- " << endl;
		cout << " Name: " << this->name << endl;
	}
	void Type() override
	{
		cout << " Type: " << this->type << endl;
	}
	void Sound() override
	{
		cout << " Sound: " << "kur - kur" << endl;
	}
};

class Hamster : virtual public Pets
{
public:
	Hamster()
	{
		this->name = "Pushok";
		this->type = "Hamster";
	}
	void Show() override
	{
		cout << "\n --- Info --- " << endl;
		cout << " Name: " << this->name << endl;
	}
	void Type() override
	{
		cout << " Type: " << this->type << endl;
	}
	void Sound() override
	{
		cout << " Sound: " << "pi - pi" << endl;
	}
};

int main()
{
	uint32_t size = 4;
	Pets** pets = new Pets * [size] 
	{
		new Dog(), new Cat(), 
	    new Parrot(), new Hamster()
	};

	for (size_t i = 0; i < size; i++)
	{
		pets[i]->Show();
		pets[i]->Type();
		pets[i]->Sound();
	}

	return 0;
}