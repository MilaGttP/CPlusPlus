
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

template<typename T>
class FileData
{
protected:
	string binFile;
	fstream stream;
public:
	FileData() = default;
	FileData(string fileName) { this->binFile = fileName; }
	~FileData() = default;
	bool Save(T* object)
	{
		try
		{
			this->stream.open(binFile, ios::out | ios::binary);
			if (!stream.is_open())
				throw;
			else
			{
				T buf = *object;
				stream.write((char*)&buf, sizeof(buf));
				stream.close();
			}
			return true;
		}
		catch (const ifstream::failure& e)
		{
			cout << e.what() << endl;
			return false;
		}
	}
	T* Load(string fileName)
	{
		try
		{
			T* object = new T;
			this->stream.open((fileName), ios::in | ios::binary);
			if (!stream.is_open())
				throw;
			else
			{
				T buf;
				stream.read((char*)&buf, sizeof(buf));
				*object = buf;
				stream.close();
			}
			return object;
		}
		catch (const ifstream::failure& e)
		{
			cout << e.what() << endl;
			return nullptr;
		}
	}
};

class Country
{
protected:
	uint32_t population;
	char countryName[25];
	char cityName[25];
public:
	Country() = default;
	~Country() = default;
	Country(uint32_t population, string countryName, string cityName)
	{
		this->population = population; 
		strcpy(this->countryName, countryName.c_str());
		strcpy(this->cityName, cityName.c_str());
	}
	friend ostream& operator << (ostream& out, Country object)
	{
		out << object.population;
		out << object.countryName;
		out << object.countryName;		
		return out;
	}
	friend istream& operator >> (istream& in, Country object)
	{
		in >> object.population;
		in >> object.countryName;
		in >> object.countryName;
		return in;
	}
	bool operator == (Country other)
	{
		this->population = other.population;
		return true;
	}
};

int main()
{
	Country country;
	vector <Country> countries;
	uint32_t tmp;
	cout << "Menu: " << endl;
	cout << "\t1 - Save" << endl;
	cout << "\t2 - Load" << endl;
	cout << "\t3 - Add country" << endl;
	cout << "\t4 - Show country" << endl;
	cout << "\t5 - Delete country" << endl;
	cout << "\t6 - Exit" << endl;
	cout << "Enter: " << endl; cin >> tmp;
	switch (tmp)
	{
	case 1:
	{
		Country* coun = new Country(42000000, "Ukraine", "Vinnitsia");
		FileData <Country> data("CountryData.bin");
		data.Save(coun);
		break;
	}
	case 2:
	{
		Country* coun = new Country();
		FileData <Country> data("CountryData.bin");
		coun = data.Load("CountryData.bin");
		break;
	}
	case 3:
	{
		uint32_t popul; string countryname; string cityname;
		system("cls");
		cout << "Enter population: ";
		cin >> popul;
		cout << "Enter country name: ";
		getline(cin, countryname);
		cout << "Enter city name: ";
		getline(cin, cityname);
		Country c(popul, countryname.c_str(), cityname.c_str());
		countries.push_back(c);
		break;
	}
	case 4:
	{
		system("cls");
		cout << "Your countries: " << endl;
		copy(countries.begin(), countries.end(), ostream_iterator<Country>(cout, ""));
		cout << "\t";
		break;
	}
	case 5:
	{
		system("cls");
		cout << "Enter desired country: ";
		cin >> country;
		for (vector <Country>::iterator it = countries.begin(); it != countries.end(); ++it)
		{
			if (*it == country)
			{
				it = countries.erase(it);
				break;
			}
			else
				++it;
			break;
		}
	}
	case 6:
	{
		exit(0);
		break;
	}
	}
	return 0;
	
}