#include "Association.h"


Association::Association()
{
	surname_ = "null";
	Group_ = 0;
	Record_Book_ = 0;
}

Association::Association(string surname, short Group,  int Record_Book)
{
	this->surname_ = surname;
	this->Group_ = Group;
	this->Record_Book_ = Record_Book;
}

Association::Association(const Association& right)
{
	this->surname_ = right.surname_;
	this->Group_ = right.Group_;
	this->Record_Book_ = right.Group_;
}

Association& Association::operator=(const Association& right)
{
	if (this != &right) {
		this->surname_ = right.surname_;
		this->Group_ = right.Group_;
		this->Record_Book_ = right.Record_Book_;
	}

	return *this;
}

Association::~Association()
{
}

istream& operator>>(istream& in, Association& right)
{
	in >> right.surname_;
	in >> right.Group_;
	in >> right.Record_Book_;
	return in;
}

ostream& operator<<(ostream& out, const Association& right)
{
	out << right.surname_ << ' ';
	out << right.Group_ << ' ';
	out << right.Record_Book_ << ' ';
	return out;
}