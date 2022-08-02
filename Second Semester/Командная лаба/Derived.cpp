#include "Derived.h"


Derived::Derived()
{
	mark_ = 0;
	surname_ = "null";
	Group_ = 0;
	Record_Book_ = 0;
}

Derived::Derived(short mark, string surname, short Group, int Record_Book)
{
	this->mark_ = mark;
	this->surname_ = surname;
	this->Group_ = Group;
	this->Record_Book_ = Record_Book;
}

Derived::Derived(const Derived& right)
{
	this->mark_ = right.mark_;
	this->surname_ = right.surname_;
	this->Group_ = right.Group_;
	this->Record_Book_ = right.Record_Book_;
}

Derived& Derived::operator=(const Derived& right)
{
	if (this != &right) {
		this->mark_ = right.mark_;
		this->surname_ = right.surname_;
		this->Group_ = right.Group_;
		this->Record_Book_ = right.Record_Book_;
	}
	return *this;
}

short Derived::GetMark()
{
	return mark_;
}

string Derived::GetSurname()
{
	return surname_;
}

short Derived::GetGroup()
{
	return Group_;
}

 int Derived::GetRecordBook()
{
	return Record_Book_;
}

 Derived::~Derived()
 {
 }


istream& operator>>(istream& in, Derived& right)
{
	in >> right.mark_;
	in >> right.surname_;
	in >> right.Group_;
	in >> right.Record_Book_;
	return in;
}

ostream& operator<<(ostream& out, const Derived& right)
{
	out << right.mark_ << ' ';
	out << right.surname_ << ' ';
	out << right.Group_ << ' ';
	out << right.Record_Book_ << ' ';
	return out;
}
