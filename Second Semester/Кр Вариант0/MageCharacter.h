#pragma once
#include "Character.h"


class MageCharacter : public Character
{
private:

	size_t max_mana_;
	size_t current_mana_;
	size_t* arr_;
	size_t Month_;


public:
	MageCharacter();
	MageCharacter(string name, State state, Race race, bool move, size_t max_mana, size_t current_mana_, size_t* arr, size_t Month);
	MageCharacter(const MageCharacter&);

	void SetMaxMana(size_t max_mana);
	size_t GetMaxMana();

	void SetCurrentMana(size_t current_mana);
	size_t GetCurrentMana();

	void SetArr(size_t Month_); 
	size_t* GetArr();

	void SetMonth(size_t Month);
	size_t GetMonth();

	MageCharacter& operator = (const MageCharacter&);

	friend ostream& operator << (ostream& out,  MageCharacter&);

	void print(ostream&) override final;

	~MageCharacter();
};

