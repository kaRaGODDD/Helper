#include "Flower.h"


void Flower::clone(const Flower& right)
{
	number = right.number;
	form = right.form;
	flowers.clear();
	flowers.assign(right.flowers.begin(), right.flowers.end());
}

Flower::Flower() : number(0), form("empty") {}

Flower::Flower(size_t number_, std::string form_, std::list<std::string> flowers_) :
	number(number_), form(form_)
{
	flowers.assign(flowers_.begin(), flowers_.end());
}

Flower::Flower(const Flower& right)
{
	clone(right);
}

Flower::~Flower()
{
}

Flower& Flower::operator=(const Flower& right)
{
	if (this != &right) {
		clone(right);
	}
	return *this;
}

void Flower::setNumber(size_t number_)
{
	this->number = number_;
}

void Flower::setForm(std::string form_)
{
	this->form = form_;
}

void Flower::setFlowers(std::list<std::string> lst)
{
	flowers.clear();
	flowers.assign(lst.begin(), lst.end());
}

size_t Flower::getNumber() const
{
	return number;
}

std::string Flower::getForm() const
{
	return form;
}

std::list<std::string> Flower::getFlowers() const
{
	return flowers;
}


std::ostream& operator<<(std::ostream& out, const Flower& right)
{
	out << "Номер клумбы: " << right.number << "\n";
	out << "Форма клумбы: " << right.form << "\n";
	out << "Список цветов:\n";
	for (const auto& x : right.flowers) {
		out << std::left << x  << "\n";
	}
	out << "\n\n";
	return out;
}

