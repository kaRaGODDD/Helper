

													/*Вывести список всех слов, хранящихся в текстовом файле(set).
													Подсчитать количество вхождений каждого слова в текстовом файле.
													Использовать класс map<string, int>.Прописные и строчные буквы :*/



#include <iostream>
#include <map>
#include <fstream> 
#include <string> 
#define br "\n"


using namespace std;


void close(ifstream& fin)
{
	fin.close();
}

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
	cout << br;
}

void solve(map <string,int>& wordsCount, ifstream& fin, string& word)
{
    if (fin.is_open())
        while (fin >> word)
        {
                wordsCount[word]++; 
        }
    else
    {
        cout << "Couldn't open the file." << endl;
        exit(1);
    }
}


void PrintMap(map<string, int> map)
{
    typedef std::map<string, int>::iterator iterator; // for (const auto& x : map)
                                                      // cout << x.first << ":" << x.second;
    for (iterator p = map.begin(); p != map.end(); p++)
        cout << p->first << ": " << p->second << endl;
}

void all()
{
    ifstream fin("in.txt");
	string word;
    map<string, int> wordsCount;
	cheker(fin);
    solve(wordsCount, fin,word);
    PrintMap(wordsCount);
	close(fin);
}

int main(void)
{
  
    all();

    system("pause");
}