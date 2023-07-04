#include "lib.h"

timer::timer()
{
	_start = std::chrono::high_resolution_clock::now();
}

timer::~timer()
{
	_end = std::chrono::high_resolution_clock::now();
	_duration = _end - _start;
	std::cout << "\nDuration is: -> " << _duration.count() << "s\n";
	
}


