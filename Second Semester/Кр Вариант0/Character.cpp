#include "Character.h"

short Character::counter = 1;

Character::Character() : ID(counter++), name_("null"), state_(State::dead), race_(Race::elf), move_(false)
{}

Character::Character(string name, State state, Race race, bool move) : ID(counter++), name_(name), state_(state), race_(race), move_(move)
{}

Character::Character(const Character& right) : ID(right.ID), name_(right.name_), state_(right.state_), race_(right.race_), move_(right.move_)
{}

short Character::GetID()
{
	return ID;
}

void Character::SetName(string name)
{
	this->name_ = name;
}

string Character::GetName()
{
	return name_;
}

void Character::SetState(State state)
{
	this->state_ = state;
}

State Character::GetState()
{
	return state_;
}

void Character::SetRace(Race race)
{
	this->race_ = race;
}

Race Character::GetRace()
{
	return race_;
}

void Character::SetMove(bool move)
{
	this->move_ = move;
}

bool Character::GetMove()
{
	return move_;
}

Character& Character::operator=(const Character& right)
{
	if (this != &right) {
		this->name_ = right.name_;
		this->state_ = right.state_;
		this->race_ = right.race_;
		this->move_ = right.move_;
	}
	return *this;
}

bool Character::operator==(const Character& right)
{
	return this->name_ == right.name_ && this->move_ == right.move_ && this->state_ == right.state_ && this->race_ == right.race_;
}


void Character::print(ostream& out)
{
	out << "ID: " << ID << '\n';
	out << "Name: " << name_ << '\n';

	switch (state_)
	{
	case State::dead:
		out << "State: dead " << '\n';
		break;
	case State::normal:
		out << "State: normal " << '\n';
		break;
	case State::paralyzed:
		out << "State: paralyzed " << '\n';
		break;
	}

	switch (race_)
	{
	case Race::dwarf:
		out << "Race: dwarf " << '\n';
		break;
	case Race::elf:
		out << "Race: elf " << '\n';
		break;
	case Race::human:
		out << "Race: human " << '\n';
		break;
	}

	switch (move_)
	{
	case 1:
		cout << "Ability to move: of course " << '\n';
		break;
	case 0:
		cout << "Ability to move: can not " << '\n';
		break;
	}
}

Character::~Character()
{
}

ostream& operator<<(ostream& out, Character& right)
{
	right.print(out);
	return out;
}
