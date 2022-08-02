#pragma once
#include "Student.h"

class Association
{
private:
    string surname_;
    short Group_;
    int Record_Book_;
public:
    Association();
    Association(string surname, short Group, int Record_Book);
    Association(const Association&);

    Association& operator = (const Association&);

    friend istream& operator >> (istream& in, Association&);
    friend ostream& operator << (ostream& out, const Association&);


    ~Association();
};

