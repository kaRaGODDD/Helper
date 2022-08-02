#ifndef _FLOWER_H
#define _FLOWER_H

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <iomanip>
#include <regex>
#include <conio.h>
#include <iterator>
#include <list>
#include <Windows.h>



class Flower
{
private:

	size_t number;
	std::string form;
	std::list<std::string> flowers;
	void clone(const Flower&);

public:
	Flower();
	Flower(size_t number_, std::string form, std::list<std::string> flowers_);
	Flower(const Flower&);

	~Flower();

	Flower& operator = (const Flower&);

	void setNumber(size_t number_);
	void setForm(std::string form_);
	void setFlowers(std::list<std::string> lst);


	size_t getNumber() const;
	std::string getForm() const;
	std::list<std::string> getFlowers() const;

	

	friend std::ostream& operator << (std::ostream& out, const Flower&);

};

#endif 
