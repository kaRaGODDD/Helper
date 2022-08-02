#pragma once
#ifndef _DRIVER_H
#define _DRIVER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <Windows.h>
#include <algorithm>
#include <list>
#include <string>
#include <map>
#include <iomanip>
#include <conio.h>


struct Driver
{
	int number_of_marsh{};
	std::string name{};
	int number_of_bus{};
	std::string mark{};

	Driver() = default;

	Driver(std::string name_, int number_of_bus_, std::string mark_) :
		name(name_), number_of_bus(number_of_bus_), mark(mark_) {}

	friend std::istream& operator >> (std::istream& in, Driver& right) {
		in >> right.number_of_marsh;
		in >> right.name;
		in >> right.number_of_bus;
		in >> right.mark;
		return in;
	}

	friend std::ostream& operator << (std::ostream& out, const Driver& right) {
		out << "Водитель: " << right.name << "\n";
		out << "Номер автобуса: " << right.number_of_bus << "\n";
		out << "Марка автобуса: " << right.mark << "\n";
		out << "\n\n";
		return out;
	}


};

#endif
