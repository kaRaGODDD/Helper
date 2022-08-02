#pragma once

#include "Student.h"

class LearningStudent
{
private:
    short Group_;
    long int Record_Book_;
    short math_;
    short Geo_;
    short Programming_;
public:
    LearningStudent();
    LearningStudent(short Group, long int Record_Book, short math, short Geo, short Programming);
    LearningStudent(const LearningStudent& right);
    LearningStudent& operator = (const LearningStudent& right);
    friend istream& operator >> (istream& in, LearningStudent&);
    friend ostream& operator << (ostream& out, const LearningStudent&);
    short GetGroup();
    long int GetRecord_Book();
    short GetMath();
    short GetGeo();
    short GetProgramming();
    ~LearningStudent();
};
