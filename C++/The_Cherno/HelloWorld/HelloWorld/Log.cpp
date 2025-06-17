#include <iostream>
#include "Log.h"

void Log(const char* message) // `const char*` is a basically a string.
{
	std::cout << message << std::endl;
}