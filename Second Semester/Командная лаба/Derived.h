#pragma once
#include "Student.h"
class Derived
{
private:
    short mark_;
    string surname_;
    short Group_;
    int Record_Book_;
public:
    Derived();
    Derived(short mark, string surname, short Group,  int Record_Book);
    Derived(const Derived&);

    friend istream& operator >> (istream& in, Derived&);
    friend ostream& operator <<(ostream& out, const Derived&);
    Derived& operator = (const Derived&);


    short GetMark();
    string GetSurname();
    short GetGroup();
    int GetRecordBook();

    

    ~Derived();
}; // общий класс 

