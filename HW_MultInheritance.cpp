#include <iostream>
using namespace std;

template <class T1, class T2>
class Base
{
protected:
	T1 value1;
	T2 value2;
public:
	Base() = default;
	~Base() = default;
	virtual void Show() = 0;
};

template <class T1, class T2, class T3, class T4>
class Child : public Base <T1, T2>
{
protected:
	T3 value3;
	T4 value4;
public:
	Child() = default;
	~Child() = default;
	Child(T3 value3, T4 value4)
	{
		this->value3 = value3;
		this->value4 = value4;
	}
	void Show() override
	{
		cout << endl << "Value3 = " << this->value3 << endl
			<< "Value4 = " << this->value4 << endl << endl;
	}
};

template <class T1, class T2, class T5, class T6>
class Child2 : public Base <T1, T2>
{
protected:
	T5 value5;
	T6 value6;
public:
	Child2() = default;
	~Child2() = default;
	Child2(T5 value5, T6 value6)
	{
		this->value5 = value5;
		this->value6 = value6;
	}
	void Show() override
	{
		cout << "Value5 = " << this->value5 << endl
			<< "Value6 = " << this->value6 << endl;
	}
};

int main()
{
	Child <string, string, string, string> child("summer", "winter");
	child.Show();

	Child2 <string, string, string, string> child2("autumn", "spring");
	child2.Show();

	return 0;
}