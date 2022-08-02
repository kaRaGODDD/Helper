#include <iostream>
#include <fstream>
#include <vector>
#define br "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input.txt");
	ofstream fout("out.txt");
	int n;
	fin >> n;
	vector <int> a(n);

	

	if (fin.peek() != EOF)
	{
		for (int i = 1; i < a.size(); ++i)
		{
			fin >> a[i];
		}
		for (int i = 1; i < a.size(); ++i)
		{
			fout << a[i] << ' ';
		}
		fout << br;
		for (int i = 1; i < a.size(); ++i)
		{
			if (a[i] % 2 == 1 && i > 2)
			{
				a[i] = i;
				fout << a[i] << ' ';
			}

		}
	}
	if (fin.peek() == EOF)
	{
		fout.clear();
		fout << "0 0";
	}
	fin.close();
	fout.close();
	return 0;
}