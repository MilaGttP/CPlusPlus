
#include <iostream>
using namespace std;

class Square
{
protected:
	double side;
public:
	Square(double side) { this->side = side; }
	double GetSide() { return this->side; }
};

class Circle
{
protected:
	double radius;
public:
	Circle(double radius) { this->radius = radius; }
	double GetRadius() { return this->radius; }
};

class CircleInSquare : virtual public Circle, virtual public Square
{
public:
	CircleInSquare(double side, double rad) : Square(side), Circle(rad) {}
	double Rad() 
	{ 
		this->radius = this->side / 2; 
		return this->radius;
	}
};

int main()
{
    double side = 4.1; double rad = 3.8;
    CircleInSquare circleInSquare = CircleInSquare(side, rad);
    cout << "CircleInSquare circle radius: " << circleInSquare.Rad() << endl;
    return 0;
}