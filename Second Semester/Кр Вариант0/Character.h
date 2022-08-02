#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <conio.h>

using namespace std;

enum class State
{
	normal,
	paralyzed,
	dead
};

enum class Race
{
	human,
	dwarf,
	elf
};


class Character
{
protected:
	static short counter;
	const short ID;
	string name_;
	State state_;
	Race race_;
	bool move_;
public:
	Character();
	Character(string name, State state, Race race, bool move);
	Character(const Character&);

	short GetID();

	void SetName(string name);
	string GetName();

	void SetState(State state);
	State GetState();

	void SetRace(Race race);
	Race GetRace();

	void SetMove(bool move);
	bool GetMove();

	Character& operator = (const Character&);

	bool operator == (const Character&);
	
	friend ostream& operator << (ostream& out, const Character&);

	virtual void print(ostream&);
                                                         
	virtual ~Character();
};

