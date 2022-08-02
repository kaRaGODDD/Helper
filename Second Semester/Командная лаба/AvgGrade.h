#pragma once
#include "Student.h"
class AvgGrade
{
private:
    short mark_;
public:

    AvgGrade();
    AvgGrade(short mark);
    AvgGrade(const AvgGrade&);

    AvgGrade& operator = (const AvgGrade&);

    friend istream& operator >> (istream& in, AvgGrade&);
    friend ostream& operator << (ostream& out, const AvgGrade&);

    ~AvgGrade();
};

