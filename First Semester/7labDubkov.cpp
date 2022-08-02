




                    /*2. —трока состоит из слов, разделенных одним или несколькими
                      пробелами.—реди слов, состо€щих только из цифр, найти слово, найти
                    максимальное и поставить его в начало строки.≈сли таких слов больше
                    одного, вз€ть предпоследнее из них.*/







#define br "\n"
#include <string>
#include <sstream>
#include <iostream>
#include <Windows.h>

using namespace std;


void getString(string& s,string& s1)
{
        cout << "Input the string" << "\n";
        getline(cin, s);
        s1 = s;
        if (s.empty())
        {
            cout << "Your string is emty, try again" << br;
            Sleep(1500);
            system("cls");
            getString(s, s1);
        }
}



void replace(string& s)
{
    int i = 0;

    while (s[i])
    {
        if (isalpha(s[i]))
        {
            s[i] = ' ';
        }
        ++i;
    }
    cout << "after replace:   " << s << br;
}

void find(string& s,int& max, int& previous_max)
{
    int n = 0;

    istringstream ss(s);

    while (ss >> n)
    {
        if (max < n)
        {
            previous_max = max;
            max = n;
        }

        if (previous_max < n && n < max)
        {
            previous_max = n;
        }
    }

    cout << "Max: " << max << br;
    cout << "Previous max: " << previous_max << br;
}

void insert(string& s,string& s1,string& for_max,int& max )
{
    cout << "After insert:" << br;
    for_max = to_string(max) + " ";
    s1.insert(0, for_max);
    cout << s1 << br;
}


void all()
{
    int max = 0;
    int previous_max = 0;
    string s, s1, for_max;
    getString(s, s1);
    replace(s);
    find(s, max, previous_max);
    insert(s, s1, for_max, max);
}


int main()
{
    all();
    system("pause");
}







/*int max = 0;
int previous_max = 0;
int i = 0;
int n = 0;


string s, s1, for_max;
getString(s,s1);
s1 = s;

while (s[i])
{
    if (isalpha(s[i])) // replace characters to 'space'
    {
        s[i] = ' ';
    }
    i++;
}
cout << "-alpha: " << s << br;


istringstream ss(s);


while (ss >> n)
{
    if (max < n)
    {
        previous_max = max;
        max = n;
    }
    if (previous_max < n && n < max)
    {
        previous_max = n;
    }
}


cout << "max: " << max << br;
cout << "previous max: " << previous_max << br;


cout << "After insert:" << br;
for_max = to_string(max) + " ";
s1.insert(0, for_max);
cout << s1 << br;
system("pause");
return 0;
}*/


































/*bool notDigits(char x)
{
    return (x < '0' || x>'9');
}

void Digits(string& s)
{
    s.erase(s.find_last_not_of(" ") + 1); // Remove spaces at the end of the string		  
    s.erase(0, s.find_first_not_of(" ")); //Remove spaces at the begining of the string
    s.push_back(' ');
    replace_if(s.begin(), s.end(), notDigits, ' '); // remove characters from string if not digits

    istringstream ss(s);
    int n;


    cout << "The string which consist of digits :";

    while (ss >> n)
    {
        cout << n << ' ';
    }
    cout << "\n";
}*/