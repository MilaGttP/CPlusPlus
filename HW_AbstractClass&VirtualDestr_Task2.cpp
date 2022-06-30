
#include <iostream>
#include <fstream>
using namespace std;

class Shape
{
protected:
	double x;
	double y;
public:
	Shape()
	{
		this->x = 0; this->y = 0;
	}
	Shape(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	~Shape()
	{
		this->x = 0; this->y = 0;
	}
	virtual void Show() = 0;
	virtual void Save(string fileName) = 0;
	virtual void Load(string fileName) = 0;
};

class Square : virtual public Shape
{
protected:
	double side;
public:
	Square() : Shape() { this->side = 0; }
	Square(double x, double y, double side) : Shape(x, y)
	{
		this->side = side;
	}
	~Square() = default;
	void Show() override
	{
		cout << endl << "Square information: " << endl
			<< "Coords: " << this->x << ", " << this->y << endl
			<< "Side: " << this->side << endl << endl;
	}
	void Save(string fileName) override
	{
		ofstream fout;
		fout.open(fileName, ofstream::app);
		if (!fout.is_open())
			cout << "File opening error! " << endl;
		else
		{
			cout << endl << "File opened!" << endl;
			fout.write((char*)this, sizeof(Square));
		}
		fout.close();
	}
	void Load(string fileName) override
	{
		ifstream fin;
		fin.open(fileName);
		if (!fin.is_open())
			cout << "File opening error! " << endl;
		else
		{
			cout << endl << "File opened!" << endl;
			Square sq;
			while (fin.read((char*)&sq, sizeof(Square)))
				this->Show();
		}
		fin.close();
	}
};

class Rectangle : virtual public Shape
{
protected:
	double width;
	double length;
public:
	Rectangle() : Shape()
	{
		this->width = 0; 
		this->length = 0;
	}
	Rectangle(double x, double y, double width, double length) : Shape(x, y)
	{
		this->width = width; 
		this->length = length;
	}
	Rectangle(double width, double length)
	{
		this->width = width;
		this->length = length;
	}
	~Rectangle() = default;
	void Show() override
	{
		cout << endl << "Rectangle information: " << endl
			<< "Coords: " << this->x << ", " << this->y << endl
			<< "Sides: " << this->width << ", " << this->length << endl << endl;
	}
	void Save(string fileName) override
	{
		ofstream fout;
		fout.open(fileName, ofstream::app);
		if (!fout.is_open())
			cout << "File opening error! " << endl;
		else
		{
			cout << endl << "File opened!" << endl;
			fout.write((char*)this, sizeof(Rectangle));
		}
		fout.close();
	}
	void Load(string fileName) override
	{
		ifstream fin;
		fin.open(fileName);
		if (!fin.is_open())
			cout << "File opening error! " << endl;
		else
		{
			cout << endl << "File opened!" << endl;
			Rectangle rc;
			while (fin.read((char*)&rc, sizeof(Rectangle)))
				this->Show();
		}
		fin.close();
	}
};

class Circle : virtual public Shape
{
protected:
	double radius;
public:
	Circle() : Shape() { this->radius = 0; }
	Circle(double x, double y, double radius) : Shape(x, y)
	{
		this->radius = radius;
	}
	~Circle() = default;
	void Show() override
	{
		cout << endl << "Circle information: " << endl
			<< "Coords: " << this->x << ", " << this->y << endl
			<< "Radius: " << this->radius << endl << endl;
	}
	void Save(string fileName) override
	{
		ofstream fout;
		fout.open(fileName, ofstream::app);
		if (!fout.is_open())
			cout << "File opening error! " << endl;
		else
		{
			cout << endl << "File opened!" << endl;
			fout.write((char*)this, sizeof(Circle));
		}
		fout.close();
	}
	void Load(string fileName) override
	{
		ifstream fin;
		fin.open(fileName);
		if (!fin.is_open())
			cout << "File opening error! " << endl;
		else
		{
			cout << endl << "File opened!" << endl;
			Circle cr;
			while (fin.read((char*)&cr, sizeof(Circle)))
				this->Show();
		}
		fin.close();
	}
};

class Ellipse : virtual public Shape, public Rectangle
{
public:
	Ellipse() : Shape(), Rectangle() {}
	Ellipse(double x, double y, double width, double length) 
		: Shape(x, y), Rectangle(width, length) {}
	~Ellipse() = default;
	void Show() override
	{
		cout << endl << "Ellipse information: " << endl
			<< "Coords: " << this->x << ", " << this->y << endl
			<< "Rectangle`s sides: " << this->width << ", " << this->length << endl << endl;
	}
	void Save(string fileName) override
	{
		ofstream fout;
		fout.open(fileName, ofstream::app);
		if (!fout.is_open())
			cout << "File opening error! " << endl;
		else
		{
			cout << endl << "File opened!" << endl;
			fout.write((char*)this, sizeof(Ellipse));
		}
		fout.close();
	}
	void Load(string fileName) override
	{
		ifstream fin;
		fin.open(fileName);
		if (!fin.is_open())
			cout << "File opening error! " << endl;
		else
		{
			cout << endl << "File opened!" << endl;
			Ellipse el;
			while (fin.read((char*)&el, sizeof(Ellipse)))
				this->Show();
		}
		fin.close();
	}
};

int main()
{
	uint32_t size = 4;
	Shape** shapes = new Shape* [size]
	{
		new Square(1, 1, 5.6), 
		new Rectangle(-2, 6, 3, 7.1),
		new Circle(-3, -2, 2.2),
		new Ellipse(1, 9, 3.4, 7.6)
	};

	for (size_t i = 0; i < size; i++)
	{
		shapes[i]->Save("ShapesInfo.txt");
		shapes[i]->Load("ShapesInfo.txt");
		shapes[i]->Show();
	}

	return 0;
}