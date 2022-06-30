
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

class Car
{
protected:
	string name;
	uint32_t year;
	uint32_t engineVolume;
	string price;
public:
	Car() = default;
	~Car() = default;
	Car(string name, uint32_t year, uint32_t engineVolume, string price)
	{
		this->name = name;
		this->year = year;
		this->engineVolume = engineVolume;
		this->price = price;
	}
	uint32_t GetYear() { return this->year; }
	friend ostream& operator << (ostream& out, Car object)
	{
		out << object.name;
		out << object.year;
		out << object.engineVolume;
		out << object.price;
		return out;
	}
	friend istream& operator >> (istream& in, Car object)
	{
		in >> object.name;
		in >> object.year;
		in >> object.engineVolume;
		in >> object.price;
		return in;
	}
	bool operator == (Car other)
	{
		this->name == name;
		this->year == year;
		this->engineVolume == engineVolume;
		this->price == price;
		return true;
	}
};

template <typename T>
class ShowRoom
{
protected:
	vector <Car> cars;
public:
	void Add(Car tmp)
	{
		cars.push_back(tmp);
	}
	void ShowAll()
	{
		copy(cars.begin(), cars.end(), ostream_iterator<Car>(cout, ""));
		cout << "\t";
	}
	void Delete()
	{
		cars.erase();
	}
	void SortInAsc()
	{
		sort(cars.begin(), cars.end(), [](T c1, T c2) { return c1.GetYear() < c2.GetYear(); });
		copy(cars.begin(), cars.end(), ostream_iterator<T>(cout, ""));
	}
	void SortInDesc()
	{
		sort(cars.begin(), cars.end(), [](T c1, T c2) { return c1.GetYear() > c2.GetYear(); });
		copy(cars.begin(), cars.end(), ostream_iterator<T>(cout, ""));
	}
};


int main()
{
	Car car;
	ShowRoom <Car> cars;
	uint32_t tmp;
	cout << "Menu:" << endl;
	cout << "1 - Add car" << endl;
	cout << "2 - Show" << endl;
	cout << "3 - Delete" << endl;
	cout << "4 - Sort in ascending order" << endl;
	cout << "5 - Sort in descending order" << endl;
	cout << "6 - Exit" << endl;
	cout << "Enter: "; cin >> tmp;
	switch (tmp)
	{
	case 1:
	{
		system("cls");
		uint32_t engineVolume; uint32_t year; string name; string price;
		system("cls");
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter year: ";
		cin >> year;
		cout << "Enter engine volume: ";
		cin >> engineVolume;
		cout << "Enter price: ";
		getline(cin, price);
		Car car("Suzuki", 2018, 2.6, "8000$");
		cars.Add(car);
		break;
	}
	case 2:
	{
		system("cls");
		cout << "All cars: " << endl;
		cars.ShowAll();
		break;
	}
	case 3:
	{
		system("cls");
		cars.Delete();
		cout << "Deleted!" << endl;
		break;
	}
	case 4:
	{
		system("cls");
		cout << "Ascending sorting: " << endl;
		cars.SortInAsc();
		break;
	}
	case 5:
	{
		system("cls");
		cout << "Descending sorting: " << endl;
		cars.SortInDesc();
		break;
	}
	case 6:
	{
		exit(0);
		break;
	}
	}
	return 0;
}