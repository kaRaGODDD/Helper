#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int number, min{ 9 }, c{ 0 };
	int number1;
	double x=0.1;
	int e;
	int zxc = 0;
	cout << "Input number";
	cin >> number;
	number1 = number;
	while (number) {
		c = number % 10;
		if (c < min)
		{
			min = c;
		}
		number /= 10;
	}
	cout << min;
	cout << endl;
	
	while (number1 > 0)
	{
		int e = number1 % 10;
		
		number1 /= 10;
		 
		if (e % min != 0) {
			x *= 10;
		}
		if (e % min != 0)
		{
			zxc = zxc + (e * x);
		}
	}
	cout << "Modified number : " << zxc;


	return 0;
}

