
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

class Train
{
protected:
    string departure;
    string arrival;
    uint32_t trainNumber;

public:
    Train()
    {
        this->departure = " ";
        this->arrival = " ";
        this->trainNumber = 0;
    }
    Train(string dp, string a, int tn)
    {
        this->departure = dp;
        this->arrival = a;
        this->trainNumber = tn;
    }
    void NewTrain()
    {
        cout << "Enter departure station: ";
        cin >> this->departure;
        cout << "Enter arrival station: ";
        cin >> this->arrival;
        cout << "Enter train number: ";
        cin >> this->trainNumber;
    }
    string GetDeparture()
    {
        return this->departure;
    }
    string GetArrival()
    {
        return this->arrival;
    }
    uint32_t GetTrainNumber()
    {
        return this->trainNumber;
    }
    friend ostream& operator << (ostream& out, Train& obj);
};

ostream& operator << (ostream& out, Train& obj)
{
    return out
        << obj.departure << endl
        << obj.arrival << endl
        << obj.trainNumber << endl;
}

class RailwayStation
{
private:
    vector <Train> station;

public:
    RailwayStation()
    {
        this->station.clear();
    }
    void AddTrain()
    {
        Train* tmp = new Train();
        tmp->NewTrain();
        this->station.push_back(*tmp);
        delete tmp;
    }
    void AddTrain(Train tmp)
    {
        this->station.push_back(tmp);
    }
    void Output()
    {
        vector<Train>::iterator it = station.begin();
        for (; it != station.end(); it++)
            cout << *it << endl << endl;
    }
    void SearchByTrainNumber(uint32_t tn)
    {
        bool a = false;
        vector<Train>::iterator it = station.begin();
        for (; it != station.end(); it++)
        {
            if ((tn) == (*it).GetTrainNumber())
                cout << *it << endl << endl;
            a = true;
        }
        if (!a)
            cout << "There isn`t train with this number" << endl;
    }
    void SearchByArrival(string a)
    {
        bool b = false;
        vector<Train>::iterator it = station.begin();
        for (; it != station.end(); it++)
        {
            if (a == (*it).GetArrival())
                cout << *it << endl << endl;
            b = true;
        }
        if (!b)
            cout << "There isn`t train on this time" << endl;
    }
    void SearchByDeparture(string dp)
    {
        bool c = false;
        vector<Train>::iterator it = station.begin();
        for (; it != station.end(); it++)
        {
            if (dp == (*it).GetDeparture())
                cout << *it << endl << endl;
            c = true;
        }
        if (!c)
            cout << "There isn`t train on this time" << endl;
    }
};

int main()
{
    uint32_t switch_on;
    RailwayStation rs;
    string buff; 
    uint32_t tmp;
    cout << endl << "\tMenu: " << endl << endl;
    while (true)
    {
        cout << "\t0 - Exit" << endl;
        cout << "\t1 - Add data" << endl;
        cout << "\t2 - Show all trains" << endl;
        cout << "\t3 - Show by number" << endl;
        cout << "\t4 - Show by arrival" << endl;
        cout << "\t5 - Show by departure" << endl << endl;
        cout << "\tYour choice: ";
        cin >> switch_on;
        switch (switch_on)
        {
        case 0:
        {
            exit(0);
        }break;
        case 1:
        {
            rs.AddTrain();
        }break;
        case 2:
        {
            rs.Output();
        }break;
        case 3:
        {
            cout << "Enter train number for searching: ";
            cin >> tmp;
            rs.SearchByTrainNumber(tmp);
        }break;
        case 4:
        {
            cout << "Enter arrival station for searching: ";
            getline(cin, buff);
            rs.SearchByArrival(buff);
        }break;
        case 5:
        {
            cout << "Enter departure station for searching: ";
            getline(cin, buff);
            rs.SearchByDeparture(buff);
        }break;
        }
    }
    return 0;
}