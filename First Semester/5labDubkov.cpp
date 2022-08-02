

												/*Создать контейнер vector <int>, ввести с клавиатуры и записать в него числа, не задавая
												количество элементов при вводе.Используя соответствующие алгоритмы и методы,
												подсчитать:
												 сумму чисел;
												 общее количество чисел;
												 количество чисел, равных заданному;
												 количество чисел, удовлетворяющих условию, например, «больше, чем N»;
												 заменить все нули средним арифметическим(взять целую чсть);
												 добавить к каждому элементу вектора сумму всех чисел из заданного интервала этого же
												вектора(не числовой оси, а вектора);
												 заменить все числа, модуль которых есть четное число, на разность максимального и
												минимального элемента этого вектора;
												 удалить из последовательности все равные по модулю числа, кроме первого из них.
												Меню делать не нужно.Выдать на экран все результаты с пояснениями на русском языке.*/






#define br "\n"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <numeric>


using namespace std;



vector <int> input(vector <int>& a)
{
	int n;
	cout << "Enter numbers,if you want to stop interring press key" << br;
	while (cin >> n)
	{


		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			break;
		}
		a.push_back(n);
	}
	return a;
}


void sum_of_elements(vector <int> a)
{
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
		sum = accumulate(a.begin(), a.end(),0);
	cout << "Sum is : " << sum << endl;
}


void amount(vector <int> a)
{
	cout << "In this vector " << a.size() << " elements" << br;
}



void equal(vector <int> a)
{
	int n,equal = 0,bigger = 0;
	cout << "Input the number with which you want to compare" << br;
	cin >> n;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == n)
			equal++;
		if (a[i] > n)
			bigger++;
	}
	cout << "In this vector equal " << equal << " elements, = " << n << " and " << bigger << " elements, than " << n << br;
}

void change(vector <int> a)
{
	int arifm = 0;
	for (int i = 0; i < a.size(); i++)
		arifm += a[i];
	arifm /= a.size();
	cout << "After change :" << br;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == 0)
			a[i] = arifm;
		cout << a[i] << " ";
	}
}


void pl(vector <int> a)
{
	try
	{
		int first, last;
		cout << "Input interval" << br;
		if (first > last)
		{
			swap(first, last);
		}

		int interval = 0;

		if (first < 0 && last > a.size() - 1)
		{
			throw  exception("Error");
		}

		for (int i = first; i <= last; i++)
		{
			interval += a[i];
		}
		cout << "After + interval " << br;
		for (int i = 0; i < a.size(); i++)
		{
			a[i] += interval;
			cout << a[i] << ", ";
		}
	}
	catch (const exception& ex)
	{
		cout << "Error" << br <<ex.what();
	}
}




void chan(vector <int> a)
{
	int Max = a[0], Min = a[0];
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > Max)
			Max = a[i];
		if (a[i] < Min)
			Min = a[i];
	}
	cout << "Vector after change" << br << br;
	for (int i = 0; i < a.size(); i++)
	{
		int l = fabs(a[i]);
		if (l % 2 == 0 && l != 0)
		{
			a[i] = Max - Min;
		}
		cout << a[i] << ", ";
	}
}




void remove(vector <int> a)
{
	cout << "Vector after delete" << br;
	for (int i = 0; i < a.size(); i++)
	{
		for (int change = i + 1; change < a.size(); change++)
		{
			if (fabs(a[i]) == fabs(a[change]))
			{
				a.erase(a.begin() + change);
			}
		}
	}
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ", ";
}



void all()
{
	vector<int> a;
	input(a);
	sum_of_elements(a);
	amount(a);
	equal(a);
	change(a);
	pl(a);
	chan(a);
	remove(a);
		
}




int main()
{
	all();
	cout << br;
	system("pause");
	return 0;
}
