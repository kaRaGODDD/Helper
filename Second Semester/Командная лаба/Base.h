#pragma once
#include "Student.h"
class Base
{
private:
    string surname;
    short Math_;
    short Geo_;
    short Programming_;

public:
    Base();
    Base& operator = (const Base&);
    short GetMath();
    short GetGeo();
    short GetProgramming();
    friend istream& operator >> (istream& in, Base&);
    friend ostream& operator << (ostream& out, const Base&);
};
