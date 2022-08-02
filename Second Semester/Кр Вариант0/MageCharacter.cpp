#include "MageCharacter.h"


MageCharacter::MageCharacter() : Character(), max_mana_(0), current_mana_(0), arr_{},Month_(0)
{}

MageCharacter::MageCharacter(string name, State state, Race race, bool move, size_t max_mana, size_t current_mana_, size_t* arr, size_t Month) :
	Character(name, state, race, move) 
{
	this->max_mana_ = max_mana;
	this->current_mana_ = current_mana_;

	if (this->current_mana_ > this->max_mana_) {
		throw exception("Can not be true");
	}

	this->arr_ = arr;
	assert(Month < 12);
	this->Month_ = Month;
}





MageCharacter::MageCharacter(const MageCharacter& right) : Character(right)
{
	this->max_mana_ = right.max_mana_;
	this->current_mana_ = right.current_mana_;

	if (this->arr_ != right.arr_) {
		arr_ = new size_t[right.Month_];
		for (size_t i = 0; i < right.Month_; ++i) {
			this->arr_[i] = right.arr_[i];
		}
	}

	this->Month_ = right.Month_;
}

void MageCharacter::SetMaxMana(size_t max_mana)
{
	assert(max_mana >= 0);
	this->max_mana_ = max_mana;
}

size_t MageCharacter::GetMaxMana()
{
	return max_mana_;
}

void MageCharacter::SetCurrentMana(size_t current_mana)
{
	assert(current_mana >= 0);
	this->current_mana_ = current_mana;
}

size_t MageCharacter::GetCurrentMana()
{
	return current_mana_;
}

void MageCharacter::SetArr(size_t Month_)
{
	assert(Month_ <= 12);

	delete[] arr_;

	arr_ = new size_t[Month_];

	cout << "Created an object of size: " << Month_ << endl;
}

size_t* MageCharacter::GetArr()
{
	return arr_;
}

void MageCharacter::SetMonth(size_t Month)
{
	assert(Month <= 12);
	this->Month_ = Month;
}

size_t MageCharacter::GetMonth()
{
	return Month_;
}

MageCharacter& MageCharacter::operator=(const MageCharacter& right)
{
	Character::operator = (right);
	if (this != &right) {
		this->max_mana_ = right.max_mana_;
		this->current_mana_ = right.current_mana_;
		if (this->arr_ != right.arr_) {
			delete[] right.arr_;
			this->arr_ = new size_t[right.Month_];
			for (size_t i = 0; i < right.Month_; ++i) {
				this->arr_[i] = right.arr_[i];
			}
		}
		this->Month_ = right.Month_;
	}
	return *this;
}


void MageCharacter::print(ostream& out)
{
	Character::print(out);
	out << "Max mana: " << max_mana_ << '\n';
	out << "Current mana: " << current_mana_ << '\n';
	out << "Month: " << Month_ << '\n';
}

MageCharacter::~MageCharacter()
{
	delete[] arr_;
}

ostream& operator<<(ostream& out, MageCharacter& right)
{
	right.print(out);
	out << "Amount of max mana: " <<right.max_mana_ << '\n';
	out << "Current mana: " << right.current_mana_ << '\n';
	out << "Session : " << right.Month_ <<" Month " << '\n';
	return out;
}
