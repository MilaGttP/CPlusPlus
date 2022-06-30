
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Student
{
protected:
	uint32_t id;
	string fullName;
	uint32_t age;
	uint32_t avgMark;
public:
    Student()
    {
        this->fullName = " ";
        this->id = 0;
        this->age = 0;
        this->avgMark = 0;
    }
    Student(string fullName, uint32_t age, uint32_t id, uint32_t avg)
    {
        this->fullName = fullName;
        this->id = id;
        this->age = age;
        this->avgMark = avg;
    }
    void NewStudent()
    {
        cout << "Enter id: ";
        cin >> this->id;
        cout << "Enter full name: ";
        cin >> this->fullName;
        cout << "Enter age: ";
        cin >> this->age;
        cout << "Enter average mark: ";
        cin >> this->avgMark;
    }
    string GetFullName() { return this->fullName; }
    uint32_t GetId() { return this->id; }
    uint32_t GetAge() { return this->age; }
    uint32_t GetAvgMark() { return this->avgMark; }
    friend ostream& operator << (ostream& out, Student& obj);
};

ostream& operator << (ostream& out, Student& obj)
{
    return out
        << obj.fullName << endl
        << obj.id << endl
        << obj.age << endl
        << obj.avgMark << endl;
}

class DataBase
{
protected:
    vector <Student> base;
public:
    DataBase() { this->base.clear(); }
    void AddStudent()
    {
        uint32_t n;
        cout << "Enter quantity of students in database: ";
        cin >> n;
        Student* tmp = new Student();
        for (size_t i = 0; i < n; i++)
        {
            tmp->NewStudent();
            this->base.push_back(*tmp);
        }
        delete tmp;
    }
    void Output()
    {
        vector<Student>::iterator it = base.begin();
        for (; it != base.end(); it++)
            cout << *it << endl << endl;
    }
    void Delete()
    {
        base.clear();
        if (base.empty())
            cout << "Database was cleared!" << endl;
    }
    void Save()
    {
        string fileName;
        cin.ignore();
        cout << "Enter path for saving: ";
        getline(cin, fileName);
        ofstream fout;
        fout.open(fileName, ofstream::app);
        if (!fout.is_open())
            cout << "File opening error! " << endl;
        else
        {
            cout << endl << "File opened!" << endl;
            fout.write((char*)this, sizeof(DataBase));
        }
        fout.close();
    }
    void Load()
    {
        string fileName;
        cin.ignore();
        cout << "Enter path for loading: ";
        getline(cin, fileName);
        ifstream fin;
        fin.open(fileName);
        if (!fin.is_open())
            cout << "File opening error! " << endl;
        else
        {
            cout << endl << "File opened!" << endl;
            DataBase db;
            while (fin.read((char*)&db, sizeof(DataBase)))
                this->Output();
        }
        fin.close();
    }
};

int main()
{
    uint32_t switch_on;
    DataBase db;
    cout << endl << "\tMenu: " << endl << endl;
    while (true)
    {
        cout << "\t0 - Exit" << endl;
        cout << "\t1 - Create" << endl;
        cout << "\t2 - Show" << endl;
        cout << "\t3 - Delete database" << endl;
        cout << "\t4 - Save in .dat" << endl;
        cout << "\t5 - Load in .dat" << endl << endl;
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
            db.AddStudent();
        }break;
        case 2:
        {
            db.Output();
        }break;
        case 3:
        {
            db.Delete();
        }break;
        case 4:
        {
            db.Save();
        }break;
        case 5:
        {
            db.Load();
        }break;
        }
    }

    return 0;
}