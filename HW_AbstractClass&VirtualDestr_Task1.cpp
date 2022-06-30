
#include <iostream>
using namespace std;

class Roots
{
protected:
	double a;
	double b;
	double c;
public:
	Roots()
	{
		this->a = 0; this->b = 0; this->c = 0;
	}
	Roots(double a, double b)
	{
		this->a = a;
		this->b = b;
	}
	Roots(double a, double b, double c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	virtual double SearchRoots() = 0;
	virtual ~Roots() = default;
};

class LinearEquations : public Roots
{
public:
	LinearEquations() = default;
	LinearEquations(double a, double b) : Roots(a, b) {}
	~LinearEquations() = default;
	double SearchRoots() override
	{
		double x;
		x = (this->a && this->b) ? -b / this->a : 0;
		return x;
	}
};

class QuadraticEquations : public Roots
{
public:
	QuadraticEquations() = default;
	QuadraticEquations(double a, double b, double c) : Roots(a, b, c) {}
	~QuadraticEquations() = default;
	double SearchRoots() override
	{
		double x1, x2, d;

		if (this->a == 0.0)
			cout << "Not root equation!" << endl;

		d = this->b * this->b - 4 * this->a * this->c;
		cout << "Discriminant = " << d << endl;
		if (d > 0) 
		{
			x1 = (-b + sqrt(d)) / (2 * this->a);
			x2 = (-b - sqrt(d)) / (2 * this->a);
			cout << "x1 = " << x1 << "\t" << "x2 = " << x2 << endl;
		}
		else if (d == 0.0) 
		{
			x1 = (-b / (2 * this->a)); 
			x2 = x1;
			return x1;
		}
		else
			cout << "Equation roots not found\n";
	}
};

int main()
{
	LinearEquations linear(5, -5);
	QuadraticEquations quadratic(2, -2, -4);
	cout << "Linear roots: " << linear.SearchRoots() << endl;	
	cout << "Quadratic roots: " << quadratic.SearchRoots() << endl;
	return 0;
}