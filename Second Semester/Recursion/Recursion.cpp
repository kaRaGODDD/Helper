#include <iostream>
#include <Windows.h>
#include <conio.h>
#define br '\n'

using namespace std;



long long factorial(const long long& n) {
	if (!static_cast<char>(n)) {
		throw ("It is just a letter try again");
	}

	if (n < 0) {
		throw ("It is negative nummber");
	}

	if (n > 15) {
		throw ("number is too long");
	}

	if (n == 0 || n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

int SumDig(const long long& k) {


	if (!static_cast<char>(k)) {
		throw "char symbol";
	}
	if (k < 0) {
		throw "unnatural";
	}
	if (abs(k < 10)) {
		return k;
	}
	else
	{
		return abs((k % 10) + SumDig(k / 10));
	}
}

int countDig(const long long& count) {
	if (count == 0) {
		throw ("uwu");
	}
	if (!static_cast<char>(count)) {
		throw ("uwu");
	}
	if (count / 10 == 0) {
		return 1;
	}
	else
	{
		return 1 + countDig(count / 10);
	}
}


int SumEl(int* arr, const int* end) {
	if (arr == end) return 0;
	return (*arr) + SumEl(arr + 1, end);
}


void menu(const int& size, int* arr) {
	try
	{
		cout << "Type 1: it is factorial" << br << "Type 2: it is sum digits" << br << "Type 3: it is count of digits" << br << "Type 4: sum of array " << br;

		switch (_getch())
		{
		case '1':
			system("cls");
			long long n;
			cout << "Input number" << br;
			cin >> n;
			cout << factorial(n);
			break;
		case '2':
			system("cls");
			long long k;
			cout << "Input number" << br;
			cin >> k;
			cout << SumDig(k) << br;
			break;
		case '3':
			system("cls");
			long long count;
			cout << "Input number" << br;
			cin >> count;
			cout << countDig(count);
			break;
		case '4':
			system("cls");
			cout << "Sum of array" << br;
			cout << SumEl(arr, arr + size);
			break;
		default:
			system("cls");
			cout << "Try again..." << br;
			Sleep(4000);
			system("cls");
			menu(size, arr);
		}
	}
	catch (const char* ex)
	{
		cout << ex;
	}
}


int main() {

	const int size = 10;
	int arr[size] = { 1,4,8,2,4,1,3,7,23,4 };


	menu(size, arr);


	cout << br;
	system("pause");
	return 0;
}