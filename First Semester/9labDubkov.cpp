
					/*2. Строки текстового файла input.txt состоят из слов, разделенных одним
					или несколькими пробелами.Перед первым, а также после последнего слова
					строки пробелы могут отсутствовать.Требуется определить слово, которое
					чаще всего встречается в файле.Результат вывести на консоль в форме,
					удобной для чтения.*/



#include <string>
#include <iostream>
#include <fstream>
#include <map>
#define br "\n"

using namespace std;

void cheker(ifstream& fin)
{
	if (fin.peek() == EOF)
	{
		std::cout << "Your file is empty!" << br;
	}
	else
	{
		std::cout << "File is not empty!" << br;
	}
	if (fin.bad() == true)
	{
		cout << "File is not present!" << br;
	}
	else
	{
		cout << "File is present!" << br;
	}
	if (fin.is_open())
	{
		cout << "File is open!" << br;
	}
	else
	{
		cout << "File is not open!" << br;
	}
	cout << endl;
}

void closeFiles(ifstream& fin)
{
	fin.close();
}


void find_the_solve(ifstream& fin, map<string, int>& m, string& temp)
{

	for (temp; fin >> temp; )

		m[temp]++; // прохождение по map

	int max = 1;

	for (const auto& x : m)
	{
		if (x.second > max) 
			max = x.second;
	}

	for (const auto& x : m)
	{

		if (x.second == max)
			cout << "The most common word is :  " << x.first << br;
	}
}

//

void all()
{
	ifstream fin("input.txt");
	string temp;
	map<string, int> m;//ключ строки а значения инты
	cheker(fin);
	find_the_solve(fin, m, temp);
	closeFiles(fin);
}

int main()
{
	all();
    system("pause");
    return 0;
}