
#include <iostream>
using namespace std;

class Figure
{
protected:
	double square;
	double width;
	double length;
	double height;
	double radius;
public:
	Figure()
	{
		this->square = 0; this->width = 0;
		this->length = 0; this->height = 0; this->radius = 0;
	}
	Figure(double width, double length)
	{
		this->width = width;
		this->length = length;
	}
	Figure(double width, double length, double height)
	{
		this->width = width;
		this->length = length;
		this->height = height;
	}
	Figure(double radius)
	{
		this->radius = radius;
	}
	virtual double SearchSquare() = 0;
	virtual ~Figure() { this->square = 0; }
};

class Rectangle : public Figure
{
public:
	Rectangle() = default;
	Rectangle(double width, double length) : Figure(width, length) {}
	~Rectangle() = default;
	double SearchSquare() override
	{
		this->square = this->width * this->length;
		return this->square;
	}
};

class Circle : public Figure
{
public:
	Circle() = default;
	Circle(double radius) : Figure(radius) {}
	~Circle() = default;
	double SearchSquare() override
	{
		this->square = 3.14 * this->radius * this->radius;
		return this->square;
	}
};

class RightTriangle : public Figure
{
public:
	RightTriangle() = default;
	RightTriangle(double width, double length) : Figure(width, length) {}
	~RightTriangle() = default;
	double SearchSquare() override
	{
		this->square = (this->width * this->length) / 2;
		return this->square;
	}
};

class Trapeze : public Figure
{
public:
	Trapeze() = default;
	Trapeze(double width, double length, double height) 
		: Figure(width, length, height) {}
	~Trapeze() = default;
	double SearchSquare() override
	{
		this->square = this->height * (this->width * this->length) / 2;
		return this->square;
	}
};

int main()
{
	Rectangle* rectangle = new Rectangle(1.4, 5.2);
	cout << endl << "Rectangle square: " << rectangle->SearchSquare() << endl;

	Circle* circle = new Circle(3.1);
	cout << "Circle square: " << circle->SearchSquare() << endl;

	RightTriangle* rightTriangle = new RightTriangle(2.3, 4.5);
	cout << "Right triangle square: " << rightTriangle->SearchSquare() << endl;

	Trapeze* trapeze = new Trapeze(3.3, 4.5, 2.1);
	cout << "Trapeze square: " << trapeze->SearchSquare() << endl;

	return 0;
}