#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <conio.h>
#include <Windows.h>

using namespace std;

class Student
{
private:
	int Record_book_;
	string Surname_;
	string Name_;
	string Middle_name_;
public:
    Student();
    Student(int Record_book, string Surname, string name, string Middle_name);
    Student(const Student& right);
    Student& operator = (const Student& right);
    friend istream& operator >> (istream& in, Student&);
    friend ostream& operator << (ostream& out, const Student&);
    int GetRecord_Book();
    string GetSurname();
    string GetName();
    string GetMiddle_name();
    ~Student();
};

