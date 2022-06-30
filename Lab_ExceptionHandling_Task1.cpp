
#include <iostream>
#include <sstream>
using namespace std;

typedef string T;
class BadInt : public out_of_range
{
public:
    BadInt() : out_of_range("It isn`t an integer number!") {}
};

int main()
{
    T numStr; int n;
    for (;;)
    {
        cout << endl << "Enter an integer number: ";
        cin >> numStr;
        istringstream sin(numStr);

        try
        {
            if (!(sin >> n))
                throw BadInt();
            cout << n << endl;
        }
        catch (BadInt& el)
        {
            cout << el .what() << endl;
        }
    }

	return 0;
}