#include "Base.h"


Base::Base()
{
	surname = "null";
	Math_ = 0;
	Geo_ = 0;
	Programming_ = 0;
}

Base& Base::operator=(const Base& right)
{

	if (this != &right) {
		this->surname = right.surname;
		this->Math_ = right.Math_;
		this->Geo_ = right.Geo_;
		this->Programming_ = right.Programming_;
	}

	return *this;
}

short Base::GetMath()
{
	return Math_;
}

short Base::GetGeo()
{
	return Geo_;
}

short Base::GetProgramming()
{
	return Programming_;
}


istream& operator>>(istream& in, Base& right)
{
	in >> right.surname;
	in >> right.Math_;
	in >> right.Geo_;
	in >> right.Programming_;
	return in;
}

ostream& operator<<(ostream& out, const Base& right)
{
	out << right.surname << ' ' << right.Math_ << ' ' << right.Geo_ << ' ' << right.Programming_;
	return out;
}
