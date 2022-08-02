#include "AvgGrade.h"

AvgGrade::AvgGrade()
{
	mark_ = 0;
}

AvgGrade::AvgGrade(short mark)
{
	this->mark_ = mark;
}

AvgGrade::AvgGrade(const AvgGrade& right)
{
	this->mark_ = right.mark_;
}

AvgGrade& AvgGrade::operator=(const AvgGrade& right)
{
	if (this != &right) {
		this->mark_ = right.mark_;
	}
	return *this;
}

AvgGrade::~AvgGrade()
{
}

istream& operator>>(istream& in, AvgGrade& right)
{
	in >> right.mark_;
	return in;
}

ostream& operator<<(ostream& out, const AvgGrade& right)
{
	out << right.mark_;
	return out;
}
