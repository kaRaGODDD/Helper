#include "Translator.h"

Translator::Translator() : Literary(), publish(0)
{}

Translator::Translator(const char* name, int year, int publish, Type type, int publish_) : Literary(name, year, type), publish(publish_)
{}

Translator::Translator(const Translator& right) : Literary(right)
{
	publish = right.publish;
}

Translator& Translator::operator=(const Translator& right)
{
	Literary::operator=(right);
	if (this != &right){
		this->publish = right.publish;
	}
	return *this;
}

void Translator::SetPublish(int publish_)
{
	this->publish = publish_;
}

int Translator::GetPublish()
{
	return publish;
}

void Translator::print(ostream& out)
{
	Literary::print(out);
	out << "Publish: " << publish << "\n";
}

Translator::~Translator()
{
}

ostream& operator<<(ostream& out, Translator& right)
{
	right.print(out);
	return out;
}
