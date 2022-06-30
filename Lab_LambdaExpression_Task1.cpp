
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

int main()
{
    Number number;
    vector <Number> numbers;
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
            cout << "Enter number: ";
            cin >> tmp;
            numbers.push_back(tmp);
        }break;
        case 2:
        {
            system("cls");
            cout << "Minimum value is: ";
            cout << *min_element(numbers.begin(), numbers.end(), [](Number n1, Number n2)
                { return n1.GetNum() < n2.GetNum(); }) << endl;
        }break;
        case 3:
        {
            system("cls");
            cout << "Maximum value is: ";
            cout << *max_element(numbers.begin(), numbers.end(), [](Number n1, Number n2)
                { return n1.GetNum() < n2.GetNum(); }) << endl;
        }break;
        case 4:
        {
            system("cls");
            cout << "Descending sorting: " << endl;
            sort(numbers.begin(), numbers.end(), [](Number n1, Number n2) { return n1.GetNum() > n2.GetNum(); });
            copy(numbers.begin(), numbers.end(), ostream_iterator<Number>(cout, ""));
            cout << "\t";
        }break;
        case 5:
        {
            system("cls");
            cout << "Ascending sorting: " << endl;
            sort(numbers.begin(), numbers.end(), [](Number n1, Number n2) { return n1.GetNum() < n2.GetNum(); });
            copy(numbers.begin(), numbers.end(), ostream_iterator<Number>(cout, ""));
            cout << "\t";
        }break;
        case 6:
        {
            system("cls");
            cout << "Constant is: " << constant << endl;
            //for_each(numbers.begin(), numbers.end(), [](Number& a) { a.SetNum(a.GetNum() + constant); });
            for (auto& n : numbers) n.SetNum(n.GetNum() + constant);
            copy(numbers.begin(), numbers.end(), ostream_iterator<Number>(cout, ""));
            cout << "\t";
        }break;
        case 7:
        {
            system("cls");
            cout << "Constant is: " << constant << endl;
            //for_each(numbers.begin(), numbers.end(), [](Number& a) { a.SetNum(a.GetNum() - constant); });
            for (auto& n : numbers) n.SetNum(n.GetNum() - constant);
            copy(numbers.begin(), numbers.end(), ostream_iterator<Number>(cout, ""));
            cout << "\t";
        }break;
        case 8:
        {
            system("cls");
            cout << "Enter desired number: "; 
            cin >> number;
            for (vector <Number>::iterator it = numbers.begin(); it != numbers.end(); ++it)
            {
                if (*it == number)
                {
                    it = numbers.erase(it);
                    break;
                }
                else
                    ++it;
            }
            copy(numbers.begin(), numbers.end(), ostream_iterator<Number>(cout, ""));
            cout << "\t";
        }break;
        case 9:
        {
            system("cls");
            cout << "Your numbers: " << endl;
            copy(numbers.begin(), numbers.end(), ostream_iterator<Number>(cout, ""));
            cout << "\t";
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