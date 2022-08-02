#pragma once
#include "Literary.h"
class Translator : public Literary
{
protected:
	int publish;
public:
	Translator();
	Translator(const char* name,int year,int publish,Type tp, int publish_);
	explicit Translator(const Translator&);
	Translator& operator = (const Translator&);

	void SetPublish(int publish_);
	int GetPublish();


	void print(ostream&) override final;


	friend ostream& operator << (ostream& out, const Translator&);

	~Translator();
};

