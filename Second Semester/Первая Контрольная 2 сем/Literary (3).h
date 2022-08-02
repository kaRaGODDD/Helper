#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cassert>
#include <string.h>
#include <algorithm>
#include <Windows.h>

using namespace std;

enum class Type
{
	roman,
	story,
	poem,
	other
};
class Literary
{
protected:
	static short counter;
	const short ID = 0;
	const char* name_;
	int year_;
	const Type type_ = Type::other;
	void copy(const char*&, const char*);
	Literary();
public:
	Literary(const char* name, int year, Type type);
	Literary(const Literary&);

	short GetID();

	void SetName(const char* name);
	const char* getName() const;

	void SetYear(int year);
	int GetYear() const;

	Type GetType() const;


	Literary& operator = (const Literary& right);

	bool operator == (const Literary&);

	virtual void print(ostream&);

	friend ostream& operator << (ostream& out, const Literary&);

	virtual ~Literary();
};

