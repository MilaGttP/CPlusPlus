
#include <iostream>
using namespace std;

class Vehicle
{
protected:
	uint32_t time;
	uint32_t cost;
public:
	void SetTime(uint32_t time) { this->time = time; }
	void SetCost(uint32_t cost) { this->cost = cost; }

	uint32_t GetTime() { return time; }
	uint32_t GetCost() { return cost; }
};

class Car : public Vehicle
{
protected:
	uint32_t number;
public:
	void SetNumber(uint32_t number) { this->number = number; }
	uint32_t GetNumber() { return number; }
};

class Bike : public Vehicle
{
protected:
	string color;
public:
	void SetColor(string color) { this->color = color; }
	string GetColor() { return color; }
};

class Cart : public Vehicle {};

int main()
{
	Car car;
	car.SetTime(12); car.SetNumber(3144);
	cout << "Car`s time: " << car.GetTime() << "\n"
		<< "Car`s number: " << car.GetNumber() << endl;

	Bike bike;
	bike.SetTime(22); bike.SetColor("white");
	cout << "Bike`s time: " << bike.GetTime() << "\n"
		<< "Bike`s color: " << bike.GetColor() << endl;

	Cart cart;
	cart.SetTime(11); cart.SetCost(123);
	cout << "Cart`s time: " << cart.GetTime() << "\n"
		<< "Cart`s cost: " << cart.GetCost() << endl;

	return 0;
}