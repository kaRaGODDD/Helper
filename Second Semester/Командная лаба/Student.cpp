#include "Student.h"

Student::Student()
{
	Record_book_ = 0;
	Surname_ = "null";
	Name_ = "Null";
	Middle_name_ = "Null";
}

Student::Student(int Record_book, string Surname, string name, string Middle_name)
{
	this->Record_book_ = Record_book;
	this->Surname_ = Surname;
	this->Name_ = name;
	this->Middle_name_ = Middle_name;
}

Student::Student(const Student& right)
{
	this->Record_book_ = right.Record_book_;
	this->Surname_ = right.Surname_;
	this->Name_ = right.Name_;
	this->Middle_name_ = right.Middle_name_;
}

Student& Student::operator=(const Student& right)
{
	if (this != &right) {
		this->Record_book_ = right.Record_book_;
		this->Surname_ = right.Surname_;
		this->Name_ = right.Name_;
		this->Middle_name_ = right.Middle_name_;
	}
	return *this;
}

int Student::GetRecord_Book()
{
	return Record_book_;
}

string Student::GetSurname()
{
	return Surname_;
}

string Student::GetName()
{
	return Name_;
}

string Student::GetMiddle_name()
{
	return Middle_name_;
}

Student::~Student()
{
}

istream& operator>>(istream& in, Student& right)
{
	in >> right.Record_book_;
	in >> right.Surname_;
	in >> right.Name_;
	in >> right.Middle_name_;
	return in;
}

ostream& operator<<(ostream& out, const Student& right)
{
	out << right.Record_book_ << ' ' << right.Surname_ << ' ' << right.Name_ << ' ' << right.Middle_name_;
	return out;
}
