

												/*1.Найти все простые числа <= N.Использовать алгоритм «Решето
												Эратосфена» и контейнер set.*/





#include <iostream>
#include <set>
#define br '\n'


using namespace std;


set<int>primes;


void compute_primes(int& n)
{
	cin >> n;
	/*try
	{
	       if (n <= 0)
		   {
		     throw exception ("unnatural number");
		   }
	}
	catch (const exception &ex)
	{
	   cout << "Error" << br << ex.what() ;
	   exit(1);
	}*/
	for (int i = 2; i <= n; i++)
	{
		primes.insert(i);
	}
	
	for(int i = 2; i <= n; i++)
	{
			for (int j = i * i; j <= n; j += i)
			{    
				primes.erase(j);
			}
	}

	for (auto i : primes)
	{
		cout << i  << " ";
	}
	cout << br;
}



int main()
{
	cout << "Your prime numbers" << br;
	int n;
	
	compute_primes(n);

	system("pause");
	return 0;
}