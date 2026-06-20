#include <iostream>

class Person {
public:
  std::string name;
  int age;

  void print() const {
    std::cout << "Name: " << name << "\nAge: " << age << "\n";
  }
};

int main() {
  int x = 10;
  
  int *ptr_to_int = new int; // new int is going to allocate space for an integer in heap and return it's memory address

  *ptr_to_int = 5; // now this will store the value in the heap
  
  // int *ptr_to_int = new int(5); // this is also valid
  
  std::cout << "&x: " << &x << "\n";
  std::cout << "x: " << x << "\n";

  std::cout << "ptr_to_int: " << ptr_to_int << "\n";
  std::cout << "*ptr_to_int: " << *ptr_to_int << "\n";

  delete ptr_to_int;

  int n = 5;
  double *array = new double[n];
  
  for (int i = 0; i < n; i++)
    array[i] = i + 1;

  for (int i = 0; i < n; i++)
    printf("%.2lf ", array[i]);
  printf("\n");

  delete[] array;

  Person *person = new Person;

  (*person).name = "Jake";
  person->age = 21;

  // we can also use an -> arrow operator instead of `(*obj).member` => `obj->member`.

  (*person).print();

  delete person;

  // DMA is not something which you can garuntee, it can fail if there is not enough free memory avaiable to allocate, so using a try and catch block is preferred.

  try {
    double *big_array = new double[999999999999999];
    delete[] big_array;
  }
  catch (std::bad_alloc& exp) {
    std::cout << "bad allocation caught: " << exp.what() << "\n";
  }

  // if you don't want to use try and catch block then you can do the following

  double *big_again = new(std::nothrow) double[999999999999999];
  if (big_again == NULL)
    std::cout << "failed to allocate again!\n";
  else 
    delete[] big_again;

  // you can also overwrite an already present dynamically allocated memory (placement new operator)

  double *my_double = new double(6.9);
  std::cout << "my_double: " << my_double << "\n*my_double: " << *my_double << "\n";

  double *overwrite = new(my_double) double(6.7);
  std::cout << "overwrite: " << overwrite << "\n*overwrite: " << *overwrite << "\n";

  delete overwrite;
  
  return 0;
}
