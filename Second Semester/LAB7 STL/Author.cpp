#include "Author.h"



Author::Author() :
	surname("empty"), name("empty"), father_name("empty")
{}

Author::Author(string surname_, string name_, string father_name_)
	: surname(surname_), name(name_), father_name(father_name_)
{
	if (surname_.empty()) {
		throw exception("empty surname");
	}
	if (name_.empty()) {
		throw exception("empty name");
	}
	if (father_name_.empty()) {
		throw exception("empty father name");
	}
}

Author::Author(const Author& right) :
	surname(right.surname), name(right.name), father_name(right.father_name)
{}

Author::~Author()
{
}

void Author::SetSurname(string surname_)
{
	if (surname_.empty()) {
		throw exception("You entered an empty surname");
	}
	this->surname = surname_;
}

void Author::SetName(string name_)
{
	if (name_.empty()) {
		throw exception("You entered an empty name");
	}
	this->name = name_;
}

void Author::SetFatherName(string father_name_)
{
	if (father_name.empty()) {
		throw exception("You entered an empty father name");
	}
	this->father_name = father_name_;
}

void Author::SetAll(string sur)
{
	this->surname = sur;
	this->name = sur;
	this->father_name = sur;
}

string Author::GetSurname() const
{
	return surname;
}

string Author::GetName() const
{
	return name;
}

string Author::GetFatherName() const
{
	return father_name;
}

Author& Author::operator=(const Author& right)
{
	if (this != &right) {
		clone(right);
	}
	return *this;
}

bool Author::operator<(const Author& A)
{
	if (surname.compare(A.surname) != 0)
	{
		return surname.compare(A.surname) < 0;
	}
	else if (name.compare(A.name) != 0)
	{
		return name.compare(A.name) < 0;
	}
	else
	{
		return father_name.compare(A.father_name) < 0;
	}
}

bool Author::operator>(const Author& A)
{
	if (surname.compare(A.surname) != 0)
	{
		return surname.compare(A.surname) > 0;
	}
	else if (name.compare(A.name) != 0)
	{
		return name.compare(A.name) > 0;
	}
	else
	{
		return father_name.compare(A.father_name) > 0;
	}
}

bool Author::operator==(const Author& A)
{
	return surname.compare(A.surname) == 0;
}




void Author::read(ostream& out)
{
	out << "Surname: " << surname << "\n";
	out << "Name: " << name << "\n";
	out << "Father name: " << father_name ;
}

void Author::write(istream& in)
{
	in >> surname;
	in >> name;
	in >> father_name;
}

void Author::clone(const Author& right)
{
	this->surname = right.surname;
	this->name = right.name;
	this->father_name = right.father_name;
}

ostream& operator<<(ostream& out, Author& right)
{
	right.read(out);
	return out;
}

istream& operator>>(istream& in, Author& right)
{
	right.write(in);
	return in;
}
