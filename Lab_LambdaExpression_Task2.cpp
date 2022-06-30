
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Number
{
protected:
    int num;

public:
    Number() { this->num = 0; }
    Number(int num) : num(num) {}
    void SetNum(int num) { this->num = num; }
    int GetNum() { return this->num; }
    friend ostream& operator << (ostream& out, Number object)
    {
        out << object.num << endl;
        return out;
    }
    //T T::operator >>(const T& b) const;
    friend istream& operator >> (istream& in, Number object)
    {
        in >> object.num;
        return in;
    }
    //bool T::operator ==(const T& b) const;
    bool operator == (Number other)
    {
        this->num = other.num;
        return true;
    }
};

template <typename T>
class Functors
{
protected:
    vector <T> func;
public:
    void Add(T tmp)
    {
        func.push_back(tmp);
    }
    void Min()
    {
        cout << *min_element(func.begin(), func.end(), [](T t1, T t2)
            { return t1.GetNum() < t2.GetNum(); }) << endl;
    }
    void Max()
    {
        cout << *max_element(func.begin(), func.end(), [](T t1, T t2)
            { return t1.GetNum() < t2.GetNum(); }) << endl;
    }
    void DescendingSort()
    {
        sort(func.begin(), func.end(), [](T t1, T t2) { return t1.GetNum() > t2.GetNum(); });
        copy(func.begin(), func.end(), ostream_iterator<T>(cout, ""));
    }
    void AscendingSort()
    {
        sort(func.begin(), func.end(), [](T t1, T t2) { return t1.GetNum() < t2.GetNum(); });
        copy(func.begin(), func.end(), ostream_iterator<T>(cout, ""));
    }
    void AddConstant(int con)
    {
        for (auto& f : func) f.SetNum(f.GetNum() + con);
        copy(func.begin(), func.end(), ostream_iterator<T>(cout, ""));
    }
    void SubConstant(int con)
    {
        for (auto& f : func) f.SetNum(f.GetNum() - con);
        copy(func.begin(), func.end(), ostream_iterator<T>(cout, ""));
    }
    void Remove(T number)
    {
        for (vector <T> ::iterator it = func.begin(); it != func.end(); ++it)
        {
            if (*it == number)
            {
                it = func.erase(it);
                break;
            }
            else
                ++it;
        }
        copy(func.begin(), func.end(), ostream_iterator<T>(cout, ""));
        cout << "\t";
    }
    void ShowAll()
    {
        copy(func.begin(), func.end(), ostream_iterator<T>(cout, ""));
        cout << "\t";
    }
};

int main()
{
    Number number;
    Functors <Number> numbers;
    const int constant = 5;
    int tmp;
    while (true)
    {
        system("cls");
        cout << "MENU" << endl << endl;
        cout << "1 - add value" << endl;
        cout << "2 - find the minimum value" << endl;
        cout << "3 - find the maximum value" << endl;
        cout << "4 - sort data in descending order" << endl;
        cout << "5 - sort data in ascending order" << endl;
        cout << "6 - increase the values in the container by a constant num" << endl;
        cout << "7 - decrease values in the container by a constant num" << endl;
        cout << "8 - removing items from the container equal to the desired value" << endl;
        cout << "9 - show all" << endl;
        cout << "10 - exit" << endl << endl;
        cout << "Enter: ";
        int menu;
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            system("cls");
            cout << "Enter value: ";
            cin >> tmp;
            numbers.Add(tmp);
        }break;
        case 2:
        {
            system("cls");
            cout << "Minimum value is: ";
            numbers.Min();
        }break;
        case 3:
        {
            system("cls");
            cout << "Maximum value is: ";
            numbers.Max();
        }break;
        case 4:
        {
            system("cls");
            cout << "Descending sorting: " << endl;
            numbers.DescendingSort();
            cout << "\t";
        }break;
        case 5:
        {
            system("cls");
            cout << "Ascending sorting: " << endl;
            numbers.AscendingSort();
            cout << "\t";
        }break;
        case 6:
        {
            system("cls");
            cout << "Constant is: " << constant << endl;
            numbers.AddConstant(constant);
            cout << "\t";
        }break;
        case 7:
        {
            system("cls");
            cout << "Constant is: " << constant << endl;
            numbers.SubConstant(constant);
            cout << "\t";
        }break;
        case 8:
        {
            system("cls");
            cout << "Enter desired number: ";
            cin >> number;
            numbers.Remove(number);
        }break;
        case 9:
        {
            system("cls");
            cout << "Your numbers: " << endl;
            numbers.ShowAll();
        }break;
        case 10:
        {
            system("cls");
            cout << "Exit." << endl;
            system("pause");
        }break;
        }
        system("pause");
    }

    return 0;
}