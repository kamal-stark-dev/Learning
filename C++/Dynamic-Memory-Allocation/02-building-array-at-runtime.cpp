#include <iostream>

// ask user to enter the size of array they want to create and allocate memory for that dynamically.

int main() {
  size_t size;
  std::cout << "Enter the size of array: ";
  std::cin >> size;

  int *array = new(std::nothrow) int[size];
  if (array == NULL) {
    std::cout << "Couldn't allocate memory.\n";
    return -1;
  }

  std::cout << "Successfully allocated memory of size " << size << " :)\n";
  std::cout << "array: " << array << "\n";

  std::cout << "Deallocating the memory.\n";
  delete[] array; // deallocating memory

  return 0;
}
