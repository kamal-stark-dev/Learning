#include <iostream>
using namespace std;

template<typename T>
class GenericClass {
public:
  T x;
  T y;

  GenericClass(T val1, T val2) : x(val1), y(val2) {}

  void printValues() {
    cout << "X: " << x << "\tY: " << y << "\n";
  }
};

int main() {
  GenericClass<int> intClass(10, 20);
  GenericClass<char> charClass('f', 'k');
  GenericClass<string> stringClass("Hello", "World");

  intClass.printValues();
  charClass.printValues();
  stringClass.printValues();

  return 0;
}
