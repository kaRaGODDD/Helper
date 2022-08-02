#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x, eps, sum = 0, denom = 1, k = 1;//k - элемент последовательности
	const double E = 2.7182818284;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter eps: ";
	cin >> eps;
	if ((eps <= 0 || eps > 0.1))
	{
		cout << "Wrong value of eps";
		exit(1);
	}
	while (fabs(k) >= eps)
	{
		sum += k;
		k *= (-x / denom);
		++denom;
	}
	cout << "The sum of the numbers in the Taylor row = " << sum << endl;
	cout << "Function value = " << pow(E, -x) << endl;
	cout << sum << " = " << pow(E, -x);
	return 0;
}