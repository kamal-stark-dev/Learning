#include <iostream> // <> are used for system includes (standard library), another example: <vector>
#include "Log.h" // "" are used for local includes (relative path), another example: "../headers/Log.h"
#include "Common.h"

int main_(void)
{
	// Primitive Data Types in C++
	// int, short, long, float, double, char, bool

	Log("Hello, World!");

	const char* string = "Hello, World!"; 

	short snum = 5; // 2 bytes (-32,768 to 32,767)
	int num = 10; // 4 bytes (-2b to 2b)
	long lnum = 100000L; // 4 bytes (or 8 bytes on some systems, -2b to 2b), `l/L` is used to denote long
	unsigned int unum = 100; // 4 bytes (0 to 4b)

	float fnum = 3.14f; // 4 bytes (approx. -3.4e38 to 3.4e38), `f/F` is used to denote float
	double dnum = 3.14159; // 8 bytes (approx. -1.7e308 to 1.7e308)

	char c = 'A'; // 1 byte (ASCII character)
	char str[] = "Hello"; // 6 bytes (5 characters + null terminator)

	bool flag = true; // 1 byte (true or false), it actually takes 1 bit but we can only access memory in bytes

	std::cout << (char)65 << std::endl;

	std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}

/*
C Standard Libraries  : #include <stdio.h>
C++ Standard Libraries: #include <iostream> // the `.h` is omitted in C++ to differentiate from C
*/