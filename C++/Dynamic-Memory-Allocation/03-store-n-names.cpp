#include <iostream>

// user enters a number 'n' and then enters 'n' names, store those names in a string array.

int main() {
  // taking input for size 
  size_t size;
  std::cout << "Enter the number of names you want to store: ";
  std::cin >> size;

  // allocating memory for names 
  std::string *names = new(std::nothrow) std::string[size];
  if (!names) {
    std::cout << "Couldn't allocate memory :/\n";
    return -1;
  }

  // taking names input
  for (size_t i = 0; i < size; i++) {
    std::cin >> names[i];
  }

  // printing names 
  std::cout << "Names: [";
  for (size_t i = 0; i < size; i++) {
    std::cout << names[i] << ", ";
  }
  std:: cout << "\b\b]\n";

  // deallocating memory
  delete[] names;

  return 0;
}
