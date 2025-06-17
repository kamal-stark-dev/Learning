#include <iostream>
using namespace std;

int main(void)
{
	// conditionals are used to control the flow of the program.
	// basically performing certain tasks based on certain conditions being true.

	int x = 5;
	if (x == 5) cout << x << " is equal to 5.\n";

	const char* ptr = nullptr;
	if (ptr)
		cout << "ptr is not null.\n";
	else
		cout << "ptr is null.\n";

	return 0;
}