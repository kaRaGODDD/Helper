#ifndef _AUTHOR_H
#define _AUTHOR_H

#include <iostream>
#include <regex>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <list>
#include <conio.h>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>

using namespace std;

class Author
{
private:

	string surname;
	string name;
	string father_name;

	void read(ostream&);
	void write(istream&);
	void clone(const Author&);

public:
	Author();
	Author(string, string, string);
	Author(const Author&);

	~Author();

	void SetSurname(string surname_);
	void SetName(string name_);
	void SetFatherName(string father_name_);

	void SetAll(string sur);

	string GetSurname() const;
	string GetName() const;
	string GetFatherName() const;

	Author& operator = (const Author&);

	bool operator < (const Author&);
	bool operator > (const Author&);
	bool operator == (const Author&);
	//bool operator!= (const Author&);

	friend ostream& operator << (ostream& out, Author&);
	friend istream& operator >> (istream& in, Author&);

};

#endif