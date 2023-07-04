#pragma once
#ifndef _LIB_
#define _LIB_

#include <iostream>
#include <thread>
#include <random>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <set>
#include <string>
#include <future>
#include <queue>
#include <chrono>
#include <fstream>
#include <mutex>
#include <Windows.h>
#include <cmath>

#include "Integral.h"

class timer
{
private:
	std::chrono::time_point<std::chrono::steady_clock> _start;
	std::chrono::time_point<std::chrono::steady_clock> _end;
	std::chrono::duration<float> _duration;
public:
	timer();
	~timer();
};

#endif 
