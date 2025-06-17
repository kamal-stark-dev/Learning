#include <iostream>

int loops(void) {
	/*for (int i = 0; i < 3; i++)
	{
		std::cout << "Hello World!" << std::endl;
	}*/


	// you can do the following and it'll work just fine
	/*int i = 0;
	for (; i < 3;)
	{
		std::cout << "Hello World!" << std::endl;
		i++;
	}*/

	// for loop
	int i = 0;
	bool condition = true;
	for (; condition; )
	{
		std::cout << "Hello World!\n";
		i++;
		if (!(i < 3)) condition = false;
	}

	std::cout << "================\n";

	// while loop
	i = 0;
	while (i < 3) {

		std::cout << i << std::endl;
		i++;
	}

	std::cout << "================\n";

	// creating a for loop that runs again and again until a positive number is entered.
	bool cond = true;
	for (;cond;) {
		int num;
		std::cin >> num;
		if (num > 0) cond = false;
	}

	std::cout << "================\n";

	// do-while loop
	i = 65;
	do {
		std::cout << (char)i << " ";
		i++;
	} while (i < 'E');

	std::cout << "\n================\n";

	// continue, break and return
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			continue;
		std::cout << i << " ";
	}

	std::cout << "\n================\n";

	for (int i = 0; i < 5; i++) {
		if (i > 2)
			break;
		std::cout << i << " ";
	} // break can be used in -> loops and switch statements

	std::cout << "\n================\n";

	return 0; // return is used to exit out of the function (we can also return a value)

	std::cout << "This line will never execute because of return statement above.\n";
}