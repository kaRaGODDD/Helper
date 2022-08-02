



										/*	¬ариант 2
						¬ массиве, состо€щем из п вещественных элементов, вычислить:
						-сумму элементов массива с нечетными номерами;
						-произведение элементов массива, расположенных между первым и последним
						отрицательными элементами.
						—жать массив, удалив из него все элементы, модуль которых не превышает 1.
						ќсвободившиес€ в конце массива элементы заполнить нул€ми.
										*/








#include <iostream>
#include <math.h>
#include <ctime>
#include <iomanip>
#include <random>
using namespace std;
int main()
{
	try
	{
		srand(time(NULL));
		bool flag;
		int answer;
		int first = -1, last = -1;
		const int SIZE = 100;
		double sum = 0;
		double  complication = 1;
		int a = 0, b = 0;
		float arr[SIZE];
		cout << "1.First task" << endl;
		cout << "2.Second task" << endl;
		cout << "3.Third task" << endl;
		cout << "4.Exit" << endl;
		int str;
		cout << "Choice: ";
		cin >> str;
		switch (str)
		{
		case 1:
			cout << "Choose :(1)-random, (2)-from keyboard\n";
			cin >> answer;
			float n;
			if (answer == 1)
			{
				cout << ("Input dimention of array : ");
				cin >> n;

				if (n == 0 || n < 0)
				{
					throw ("Incorrect dimention");
				}

				cout << "Input the boundaries of the array : ";
				cout << endl;

				cin >> a >> b;
				if (a > b)
				{
					swap(b, a);
				}

				if (a == b)
				{
					throw exception ("This is not boundaries");
				}


				cout << "Random array: " << endl;
				for (int i = 0; i < n; i++)
				{

					arr[i] =  rand() / ((double)RAND_MAX) * (b-a)+a;
					//if (arr[i] <= b && arr[i] >= a)
					cout << fixed << setprecision(2) << arr[i] << " ";

				}
				cout << endl;
				for (int i = 0; i < n; i += 2)
				{
					flag = true;
					sum += arr[i];
				}
				cout << endl;
				if (!flag)
				{
					throw exception("Sum is empty");
					/*cout << "Threre is no odd numbers in array or this array consist of null " << endl;
					exit(1);*/
				}
				else
					cout << "The sum of the elements of the array with odd numbers = " << sum << endl;
				break;
			}
			if (answer == 2)
			{
				float n;
				cout << ("Input dimention of array : ");
				cin >> n;
				cout << "array from keyboard :  ";
				cout << endl;
				for (int i = 0; i < n; i++)
				{
					cin >> arr[i];
				}
				for (int i = 0; i < n; i++)
				{
					cout << arr[i] << " ";
				}
				for (int i = 0; i < n; i += 2)
				{
					sum += arr[i];
				}
				cout << endl;
				if (sum == 0)
				{
					throw exception("Sum is empty");
					/*cout << "Threre is no odd numbers in array or this array consist of null" << endl;
					exit(1);*/
				}
				else
					cout << "The sum of the elements of the array with odd numbers = " << sum << endl;
				break;
			}
		case 2:
			cout << "Choose :(1)-random, (2)-from keyboard\n";
			cin >> answer;
			float N;
			if (answer == 1)
			{
				cout << "Input dimention of array : ";
				cin >> N;
				cout << "Input the boundaries of the array : ";
				cout << endl;
				cin >> a >> b;
				if (a > b)
				{
					swap(b, a);
				}
				cout << "Random array: " << endl;
				for (int i = 0; i < N; i++)
				{
					arr[i] = a + b * rand() / (float)RAND_MAX;// числа с двум€ знаками после зап€той
					cout << fixed << setprecision(2) << arr[i] << " ";
				}
				cout << endl;
				for (int i = 0; i < N; i++)
				{
					if (arr[i] < 0)
					{
						first = i;
						break;
					}
				}
				// поиск индекса последнего отрицательного элемента
				for (int i = N; i > 0; i--)
				{
					if (arr[i] < 0)
					{
						last = i;
						break;
					}
				}
				if (first == last)
				{
					throw exception("Your first negative element = last negative element");
				}
				if (first == last-1)
				{
					throw exception("First and last negative element stay together");
				}
				if (first == -1 && last == -1)
				{
					throw exception("There no negative elements");
					/*cout << "There no negative elements";
					exit(1);*/
				}
				// произведение чисел между первым и последним отрицательным элементом
				for (int i = first + 1; i < last - 1; i++)
				{
					complication = complication * arr[i];
				}
				if (complication == 1)
				{
					throw exception("There is no negative numbers in array");
					/*cout << " there is no negative index in array ";
					exit(1);*/
				}
				else
					cout << "The product of the elements between the first and last negative number = " << complication << endl;
				break;
			}
			if (answer == 2)
			{
				float N;
				cout << "Input dimention of array : ";
				cin >> N;
				cout << "array from keyboard : ";
				cout << endl;
				for (int i = 0; i < N; i++)
				{
					cin >> arr[i];
				}
				for (int i = 0; i < N; i++)
				{
					cout << arr[i] << " ";
				}
				for (int i = 0; i < N; i++)
				{
					if (arr[i] < 0)
					{
						first = i;
						break;
					}
				}
				// поиск индекса последнего отрицательного элемента
				for (int i = N; i > 0; i--)
				{
					if (arr[i] < 0)
					{
						last = i;
						break;
					}
				}
				cout << endl;
				if (first >= 0 && last >= 0)
				{
					throw exception("There no negative elements");
					/*cout << "There no negative elements";
					exit(1);*/
				}
				// произведение чисел между первым и последним отрицательным элементом
				for (int i = first + 1; i < last - 1; i++)
				{
					complication = complication * arr[i];
				}
				cout << endl;
				if (complication == 1)
				{
					throw exception("Error");
					/*cout << " error ";
					exit(1);*/
				}
				else
					cout << "The composition of the elements between the first and last negative number = " << complication << endl;
				break;
			}
		case 3:
			cout << "Choose :(1)-random, (2)-from keyboard\n";
			cin >> answer;
			float N1;
			if (answer == 1)
			{
				cout << ("Input dimention of array : ");
				cin >> N1;
				cout << "Input the boundaries of the array";
				cout << endl;
				cin >> a >> b;
				if (a > b)
				{
					swap(b, a);
				}
				cout << "Random array: " << endl;
				for (int i = 0; i < N1; i++)
				{
					arr[i] = rand() / ((double)RAND_MAX) * (a - b) + b;
				}
				for (int i = 0; i < N1; i++)
				{
					cout << fixed << setprecision(2) << arr[i] << " ";
				}
				cout << endl;

				for (int i = 0; i < N1; i++)
				{
					if (fabs(arr[i]) <= 1)
						arr[i] = 0;
				}
				
				
				cout << endl;
				for (int i = 0; i < N1; i++)//цикл поиска и сдвига элементов равных 0
				{
					for (int k = 0; k < N1 - 1 - i; k++)
					{
						if (arr[k] == 0)
						{
							arr[k] = arr[k + 1];
							arr[k + 1] = 0;
						}
					}
				}
				//for (int i = 0; i < N1; i++)
				//{
				//	if (arr[i] >= 0)
				//	{
				//		throw exception("All of the elements in array > 0");
				//		/*cout << "All of the element in array > 0" << endl;
				//		exit(1);*/
				//	}
				//}
				for (int k = 0; k < N1; k++)
				{
					cout << arr[k] << " ";
				}
				break;
			}
			if (answer == 2)
			{
				float N1;
				cout << ("Input dimention of array : ");
				cin >> N1;
				cout << ("array from keyboard : " " ");
				cout << endl;
				for (int i = 0; i < N1; i++)
				{
					cin >> arr[i];
				}
				for (int i = 0; i < N1; i++)
				{
					cout << arr[i] << " ";
				}
				cout << endl;
				for (int i = 0; i <= N1; i++)
				{
					if (fabs(arr[i] < 1))
						arr[i] = 0;
				}
				for (int i = 0; i < N1; i++)//цикл поиска и сдвига элементов равных 0
				{
					for (int k = 0; k < N1 - 1 - i; k++)
					{
						if (arr[k] == 0)
						{
							arr[k] = arr[k + 1];
							arr[k + 1] = 0;
						}
					}
				}
				for (int i = 0; i < N1; i++)
				{
					if (arr[i] >= 0)
					{
						cout << "All of the element in array > 0" << endl;
						exit(1);
					}
				}
				for (int k = 0; k < N1; k++)
				{
					cout << arr[k] << " ";
				}
				cout << endl;
				break;
			}
		case 4:
			cout << "Goodbye" << endl;
			break;
		default://если ни одно из значений не совпало
			cout << "Incorrectly selected number" << endl;
			break;
		}
	}
	catch (const exception &ex)
	{
		cout << "We catch incorrect " << endl <<  ex.what() << endl;
	}
	
	system("pause");
	return 0;
}
