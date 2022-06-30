
#include <iostream>
using namespace std;

class Wheels
{
protected:
	double wheelSize;
public:
	Wheels(double wheelSize) { this->wheelSize = wheelSize; }
	double GetWheelSize() { return this->wheelSize; }
};

class Engine
{
protected:
	double volume;
public:
	Engine(double volume) { this->volume = volume; }
	double GetVolume() { return this->volume; }
};

class Doors
{
protected:
	string color;
public:
	Doors(string color) { this->color = color; }
	string GetColor() { return this->color; }
};

class Salon
{
protected:
	double height;
	double width;
public:
	Salon(double height, double width) 
	{ 
		this->height = height; 
		this->width = width; 
	}
	double GetHeight() { return this->height; }
	double GetWidth() { return this->width; }
};

class Mirrors
{
protected:
	double mirrorSize;
public:
	Mirrors(double mirrorSize) { this->mirrorSize = mirrorSize; }
	double GetMirrorSize() { return this->mirrorSize; }
};

class Car : virtual public Wheels, virtual public Engine, 
	virtual public Doors, virtual public Salon, virtual public Mirrors
{
public:
	Car(double wSize, double vol, string color, 
		double height, double width, double mSize) 
		:Wheels(wSize), Engine(vol), Doors(color),
		Salon(height, width), Mirrors(mSize) {}
};

int main()
{
	Car car = Car(5.5, 2.3, "black", 3.8, 1.4, 16);

	cout << "Wheel size: " << car.GetWheelSize() << "\n"
		<< "Engine volume: " << car.GetVolume() << "\n"
		<< "Doors color: " << car.GetColor() << "\n"
		<< "Salon height, width: " << car.GetHeight() << ", " << car.GetWidth() << "\n"
		<< "Mirrors size: " << car.GetMirrorSize() << endl;

	return 0;
}