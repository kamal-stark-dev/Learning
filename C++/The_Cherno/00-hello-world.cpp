#include <iostream> // anything that begins with a hash is a preprocessor statement (first thing that a compiler does)

int main(void) // main function - the entry point of our application, execution begins from here
{
    std::cout << "Hello, World!" << std::endl; // printing the "Hello, World!" text on the screen
    std::cin.get(); // will just wait for input, so when you press "Enter" the program terminates
}

// main is a special function so even if you don't return an integer (expected) it will assume `0` is returned.