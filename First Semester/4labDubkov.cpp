#include <iostream>
#include<iomanip>
#include <ctime>
#include <conio.h>//getch
#include <stdlib.h>
#include <Windows.h>
using namespace std;

int main()
{
	srand(time(0));
	int max = 0;
	int rows;
	int cols;
	int a, b;

	int first = 0;

	    no :
		cout << "Input the number of rows and cols:" << endl;
		cout << "The number of rows must be equal to the number of columns" << endl;
		cout << "\tInput rows - ";
		cin >> rows;
		cout << "\tInput cols - ";
		cin >> cols;
		cout << "";
		cout << endl;

		
		
		if (rows != cols)
		{
			cout << "try again ...";
			cout << endl;
			Sleep(1200);
			system("cls");
			goto no;
		}
	   


		if (rows == cols)
		{
			goto yes;
		}
			
		
		


	
    yes:
	cout << "(1) - random array " << "(2) - array from keyboard" << endl;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	switch (_getch())
	{
	case'1':
		cout << "Enter an interval from a to b" << endl;
		cin >> a >> b;
		cout << endl;

		if (a > b)
		{
			swap(b, a);
		}


		cout << "Matrix A:" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = rand() % (b - a + 1) + a;
				cout << setw(3) << arr[i][j] << ' ';
			}
			cout << endl;
		}
		break;



	case'2':
		cout << "Matrix B:" << endl;

		for (int i = 0; i < rows; i++)
		  for (int j = 0; j < cols; j++)
		  {
			cout << "arr[" << i << "]" << "[" << j << "] = ";
			cin >> arr[i][j];
		  }
		cout << endl;
		
		for (int i = 0; i < cols; i++) 
		{
			for (int j = 0; j < rows; j++)
				cout << setw(3) <<arr[i][j] << ' ';
			cout << endl;
		}
		break;



	default:
		cout << "Error";
		return 0;
	}
	cout << endl;


	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (i <= j)
			{
				cout << setw(3) << arr[i][j] << " ";
				if (arr[i][j] > max)
					max = arr[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << "max = " << " " << max << endl;
	cout << endl;



	int gde_null = 0;

	for (int j = 0; j < rows; j++)
	{
		if (arr[0][j] == 0)
		{
			gde_null = j;
			break;
		}
		else gde_null = -1;
	}
	for (int i = 0; i < rows; i++)
	{
		swap(arr[i][0], arr[i][gde_null]);
	}
	if (gde_null == -1)
	{
		cout << "There is no null in matrix" << endl;
	}
	else
	{
		cout << "changed array" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				cout << setw(3) << arr[i][j] << ' ';
			cout << endl;
		}
	}

	return 0;
}