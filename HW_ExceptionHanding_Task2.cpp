
#include <iostream>
#include <string>
using namespace std;

class BaseException
{
protected:
    string text;
public:
    virtual string ErrorOutput() = 0;
};

class ArithmException : public BaseException
{
public:
    ArithmException()
    {
        this->text = "Error! Arithmetic Exception!";
    }
    ArithmException(string text) { this->text = text; }
    string ErrorOutput() override { return this->text; }
};

class DivideByZero : public ArithmException
{
public:
    DivideByZero() : ArithmException()
    {
        this->text = "Divide by zero!";
    }
    DivideByZero(string text) :ArithmException(text) {}
    string ErrorOutput() override { return this->text; }
};

class NegativeIndex : public ArithmException
{
public:
    NegativeIndex() : ArithmException()
    { 
        this->text = "Negative index!";
    }
    NegativeIndex(string text) :ArithmException(text) {}
    string ErrorOutput() override { return this->text; }
};

void DemoExceptionsNegIndex()
{
    int arr[10];
    int index;

    for (int i = 0; i < 10; i++)
        arr[i] = i * i;

    cout << "Input index: ";
    cin >> index;

    if (index < 0)
        throw NegativeIndex();
    else
        cout << "arr[" << index << "] = " << arr[index] << endl;
}

void DemoExceptionsArithmExc()
{
    int a, b;
    cout << "A = "; cin >> a;
    cout << "B = "; cin >> b;

    if (b == 0)
        throw DivideByZero();
    else
        cout << "a / b = " << (double)a / b << endl;
}

int main()
{
    try
    {
        DemoExceptionsNegIndex();
        DemoExceptionsArithmExc(); 
        cout << "Good!" << endl;
    }
    catch (NegativeIndex e)
    {
        cout << e.ErrorOutput() << endl;
    }
    catch (DivideByZero e)
    {
        cout << e.ErrorOutput() << endl;
    }
    catch (exception& e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}