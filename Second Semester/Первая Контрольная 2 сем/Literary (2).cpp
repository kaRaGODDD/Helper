#include "Literary.h"

short Literary::counter = 1;

Literary::Literary() : ID(counter++), name_("Default_name"), year_(0), type_(Type::other)
{}

void Literary::copy(const char*& str1, const char* str2)
{
	if (str1)
		delete[] str1;

	if (str2) {
		str1 = new char[strlen(str2) + 1];
		strcpy(const_cast<char*>(str1), str2);
	}
}

Literary::Literary(const char* name, int year, Type type) : ID(counter++),year_(year),type_(type)
{
	copy(name_, name);
}

Literary::Literary(const Literary& right) : ID(counter++),year_(right.year_),name_(right.name_)
{
	copy(name_, right.name_);
}

short Literary::GetID()
{
	return ID;
}

void Literary::SetName(const char* name)
{
	copy(name_,name);
}

const char* Literary::getName() const
{
	return this->name_;
}

void Literary::SetYear(int year)
{
	assert(year > 0);
	year_ = year;
}

int Literary::GetYear() const
{
	return year_;
}

Type Literary::GetType() const
{
	return type_;
}

Literary& Literary::operator=(const Literary& right)
{
	if (this != &right) {
		copy(name_, right.name_);
		this->year_ = right.year_;
	}

	return *this;
}

bool Literary::operator==(const Literary& right)
{
	return this->type_ == right.type_;
}

void Literary::print(ostream& out)
{
	out << "ID: " << ID << "\n";
	out << "Name: " << name_ << "\n";
	switch (type_)
	{
	case Type::other:
		out << "Type: other" << '\n';
		break;
	case Type::poem:
		out << "Type: poem" << '\n';
		break;
	case Type::roman:
		out << "Type: roman" << '\n';
		break;
	case Type::story:
		out << "Type: story" << '\n';
		break;
	}
}

Literary::~Literary()
{
	delete[] name_;
}

ostream& operator<<(ostream& out,  Literary& right)
{
	right.print(out);
	return out;
}
