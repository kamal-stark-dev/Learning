#include <iostream>

// enums(enumerations) are just integers

enum e {
	LOW = 5, MEDIUM = 10, HIGH = 15
};

enum test : unsigned char { // you can assign types of integers (not floats though)
	A = 5, B, C
};

int enums(void) {
	e level = MEDIUM;

	//e level = 100; -> this won't work as the new type is `e` not `int`

	std::cout << "level: " << level << '\n';

	return 0;
}