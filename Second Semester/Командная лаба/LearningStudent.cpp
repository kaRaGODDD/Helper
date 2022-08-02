#include "LearningStudent.h"

LearningStudent::LearningStudent()
{
	Group_ = 0;
	Record_Book_ = 0;
	math_ = 0;
	Geo_ = 0;
	Programming_ = 0;
}

LearningStudent::LearningStudent(short Group, long int Record_Book, short math, short Geo, short Programming)
{
	this->Group_ = Group;
	this->Record_Book_ = Record_Book;
	this->math_ = math;
	this->Geo_ = Geo;
	this->Programming_ = Programming;
}

LearningStudent::LearningStudent(const LearningStudent& right)
{
	this->Group_ = right.Group_;
	this->Record_Book_ = right.Record_Book_;
	this->math_ = right.math_;
	this->Geo_ = right.Geo_;
	this->Programming_ = right.Programming_;
}

LearningStudent& LearningStudent::operator=(const LearningStudent& right)
{
	if (this != &right) {

		this->Group_ = right.Group_;
		this->Record_Book_ = right.Record_Book_;
		this->math_ = right.math_;
		this->Geo_ = right.Geo_;
		this->Programming_ = right.Programming_;
	}
	return *this;
}

short LearningStudent::GetGroup()
{
	return Group_;
}

long int LearningStudent::GetRecord_Book()
{
	return Record_Book_;
}

short LearningStudent::GetMath()
{
	return math_;
}

short LearningStudent::GetGeo()
{
	return Geo_;
}

short LearningStudent::GetProgramming()
{
	return Programming_;
}


LearningStudent::~LearningStudent()
{
}

istream& operator>>(istream& in, LearningStudent& right)
{
	in >> right.Group_;
	in >> right.Record_Book_;
	in >> right.math_;
	in >> right.Geo_;
	in >> right.Programming_;
	return in;
}

ostream& operator<<(ostream& out, const LearningStudent& right)
{
	out << right.Group_ << ' ' << right.Record_Book_ << ' ' << right.math_ << ' ' << right.Geo_ << ' ' << right.Programming_;
	return out;
}