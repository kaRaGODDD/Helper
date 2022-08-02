#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>
#define br '\n'


using namespace std;
using std::cout;


double func(double x) {
	return asin(sqrt(x)) / sqrt(x * (1 - x));
}

double func1(double x) {
	return x * x;
}

double func2(double x) {
	return tan(x);
}


void inputEps(double& eps) {
	cout << "Input epsilon" << br << "epsilon = ";
	cin >> eps;
	if (eps <= 0) {
		cout << "epsilon can`t be equal to " << eps << br << "try again...";
		Sleep(3000);
		system("cls");
		inputEps(eps);
	}
	system("cls");
}

void InputInfo(double& lower, double& upper, double& n, double& eps) {

	try
	{
		cout << "Input lower limit of integration" << br;
		cin >> lower;
		cout << "Input upper limit of integration" << br;
		cin >> upper;
		if (lower > upper)
		{
			swap(lower, upper);
		}
		system("cls");
		cout << "Input amoung of splits" << br;

		cin >> n;
		
		if (n <= 0)
		{
			throw exception("this value cannot be cannot be a split");
		}

	}
	catch (const exception& ex)
	{
		ex.what();
	}
}

double Left_Rect(const double& lower, const double& upper, const double& n, double& eps, double (*f)(double)) {
	
	double step = (upper - lower) / n;

	double sum = 0.0;
	double OtherSum = 0.0;

	double OtherStep = 2 * step;

	for (int i = 0; i <= n - 1; i++) {
		sum += step * f(lower + i * step);
	}
	for (int i = 0; i <= n - 1; i++) {
		OtherSum += OtherStep * f(lower + i * OtherStep);
	}

	int index = 0;

	while (abs(sum - OtherSum) < eps)
	{
		++index;
		sum = OtherSum;
		OtherSum += OtherStep * f(lower + index * OtherStep);
	}
	cout << "Method of left Rectangles ";
	return sum;
}

double Right_Rect(const double& lower, const double& upper, const double& n, double& eps, double (*f)(double)) {
	double step = (upper - lower) / n;
	double sum = 0.0;
	double OtherSum = 0.0;

	double OtherStep = 2 * step;

	for (int i = 1; i <= n; i++) { //справа считаем
		sum += step * f(lower + i * step);
	}
	for (int i = 1; i <= n; i++) {
		OtherSum += OtherStep * f(lower + i * OtherStep);
	}


	int index = 0;
	while (abs(sum - OtherSum) < eps)
	{
		++index;
		sum = OtherSum;
		OtherSum += OtherStep * f(lower + index * OtherStep);
	}
	cout << "Method of right Rectangles ";
	return sum;
}

double Middle_Rect(const double& lower, const double& upper, const double& n, double& eps, double (*f)(double)) {
	double sum = 0.0;
	double step = (upper - lower) / n;
	double otherSum = 0.0;
	double otherStep1 = 2 * step;

	double otherStep = step / 2;

	for (int i = 0; i < n; ++i) {
		sum += f(lower + step * (i + otherStep));
	}
	sum *= step;
	for (int i = 0; i < n; ++i) {
		otherSum += f(lower + step * (i + otherStep));
	}

	otherSum *= otherStep1;

	int index = 0;

	while (abs(sum - otherSum) < eps)
	{
		++index;
		sum = otherSum;
		otherSum += f(lower + step * (index + otherStep));
	}

	cout << "Method of middle Rectangles ";
	return sum;
}

double Trapeze_Rect(const double& lower, const double& upper, const double& n, double& eps, double (*f)(double)) {
	double sum = 0.0;
	double step = (upper - lower) / n;
	double otherSum = 0.0;
	double otherStep1 = 2 * step;
	double otherStep = step / 2; // первое + other step остальные с обычным step

	sum = f(lower) + f(upper);

	for (int i = 1; i <= n - 1; ++i) {
		sum += 2 * f(lower + i * step);
	}

	sum *= step / 2;

	otherSum = f(lower) + f(upper);

	otherStep = 2 * step;

	for (int i = 1; i <= n - 1; ++i) {
		otherSum += 2 * f(lower + i * otherStep);
	}

	otherSum *= otherStep / 2;

	int index = 0;

	while (abs(sum - otherSum) < eps)
	{
		++index;
		sum = otherSum;
		otherSum = otherSum += 2 * f(lower + index * otherStep);
	}

	cout << "Method of Trapeze Rectangles ";
	return sum;

}

double Sympson_Rect(const double& lower, const double& upper, const double& n, double& eps, double (*f)(double)) {
	double sum = 0.0;
	double step = (upper - lower) / n;
	int k;

	sum = f(lower) + f(upper);

	for (int i = 1; i <= n - 1; ++i) {
		k = 2 + 2 * (i % 2); // четность
		sum += k * f(lower + i * step);
	}

	sum *= step / 3;

	double otherSum = f(lower) + f(upper);

	double otherStep = 2 * step;

	int OtherCount = 0;

	for (int i = 0; i <= n; ++i) {
		OtherCount = 2 + 2 * (i % 2);
		otherSum += OtherCount * f(lower + i * otherStep);
	}
	otherSum *= otherStep / 3;

	int index = 0;
	while (abs(sum - otherSum) < eps)
	{
		++index;
		sum = otherSum;
		otherSum = OtherCount * f(lower + index * otherStep);
	}
	cout << "Method of Sympson Rectangles ";
	return sum;
}

void menu() {

	double n;
	double lower;
	double upper;
	double step;
	double eps;


	inputEps(eps);

	cout << "Integral of which function you would like to calculate?" << br;
	cout << "Type 1: this is  -> asin(sqrt(x)) / sqrt(x * (1 - x))" << br << "Type 2: this is  -> x*x" << br << "Type 3: this is  -> tg(x)" << br;
	switch (_getch())
	{
	case '1':
		system("cls");
		InputInfo(lower, upper, n, eps);
		cout << Left_Rect(lower, upper, n, eps, func);
		cout << br;
		cout << Right_Rect(lower, upper, n, eps, func);
		cout << br;
		cout << Middle_Rect(lower, upper, n, eps, func);
		cout << br;
		cout << Trapeze_Rect(lower, upper, n, eps, func);
		cout << br;
		cout << Sympson_Rect(lower, upper, n, eps, func);
		break;
	case '2':
		system("cls");
		InputInfo(lower, upper, n, eps);
		cout << Left_Rect(lower, upper, n, eps, func1);
		cout << br;
		cout << Right_Rect(lower, upper, n, eps, func1);
		cout << br;
		cout << Middle_Rect(lower, upper, n, eps, func1);
		cout << br;
		cout << Trapeze_Rect(lower, upper, n, eps, func1);
		cout << br;
		cout << Sympson_Rect(lower, upper, n, eps, func1);
		break;
	case '3':
		system("cls");
		InputInfo(lower, upper, n, eps);
		cout << Left_Rect(lower, upper, n, eps, func2);
		cout << br;
		cout << Right_Rect(lower, upper, n, eps, func2);
		cout << br;
		cout << Middle_Rect(lower, upper, n, eps, func2);
		cout << br;
		cout << Trapeze_Rect(lower, upper, n, eps, func2);
		cout << br;
		cout << Sympson_Rect(lower, upper, n, eps, func2);
		break;
	default:
		cout << "try again.." << br;
		Sleep(2000);
		system("cls");
		menu();
	}

}



int main() {


	menu();

	cout << br;
	system("pause");
	return 0;
}