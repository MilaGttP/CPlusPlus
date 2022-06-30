
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

class MathExpression
{
protected:
	double x, y, z, B;
public:
	MathExpression() = default;
	~MathExpression() = default;

	double FirstExpression()
	{
		cout << "--- First Expression --- \n";
		cout << "Enter x: "; cin >> this->x;
		cout << "Enter B: "; cin >> this->B;
		if (this->x > 0 && this->x < 4 && this->B > 0)
			this->y = x * sqrt(this->B * B * B);
		else if (x >= 4 && B == 1)
			y = B * sin(x) * sin(x);
		else
			y = 0;
		return this->y;
	}
	double SecondExpression()
	{
		cout << "--- Second Expression --- \n";
		cout << "Enter x: "; cin >> this->x;
		if (this->x > 0 && x <= M_PI_2)
			y = tan(x);
		else if (x > M_PI_2 && x < M_PI)
		{
			cout << "Enter B: "; cin >> this->B;
			this->y = this->B * cos(x) / sin(this->x);
		}
		else
			y = 5;
		return this->y;
	}
	double ThirdExpression()
	{
		cout << "--- Third Expression --- \n";
		cout << "Enter x: "; cin >> this->x;
		if (this->x > 2)
			this->y = x * x - 5;
		else if (x == 2)
			y = log(x) + 4;
		else
			y = x * x * x - 2;
		return this->y;
	}
	double FourthExpression()
	{
		cout << "--- Fourth Expression --- \n";
		cout << "Enter x: "; cin >> this->x;
		cout << "Enter z: "; cin >> this->z;
		if (this->x < 0)
			this->y = pow(2, ((-x) * sqrt(x - 2)));
		else if (x > 0 && x < 5 && z == 2)
			y = sqrt(pow(M_E, x + 1) + sin(z));
		else
			y = 0;
		return this->y;
	}
	double FifthExpression()
	{
		cout << "--- Fifth Expression --- \n";
		cout << "Enter x: "; cin >> this->x;
		cout << "Enter z: "; cin >> this->z;
		if (this->x < 0 && this->z > 0)
			this->y = pow(2, x) + 3 * z;
		else if (this->x < 0 && this->z < 0)
			y = pow(M_E, x - z) + x / 2;
		else
			y = x * x;
		return this->y;
	}
};

int main()
{
	MathExpression exp;
	cout << exp.FirstExpression() << endl;
	cout << exp.SecondExpression() << endl;
	cout << exp.ThirdExpression() << endl;
	cout << exp.FourthExpression() << endl;
	cout << exp.FifthExpression() << endl;
	return 0;
}