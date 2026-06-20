#include <iostream>
using namespace std;

template<typename T1, typename T2, typename T3>
class MultiType {
public:
  T1 x;
  T2 y;
  T3 z;

  MultiType(T1 val1, T2 val2, T3 val3) : x(val1), y(val2), z(val3) {}

  void printValues() {
    cout << "X: " << x << "\tY: " << y << "\tZ: " << z << "\n";
  }
};

int main() {
  MultiType<char, int, double> CIDType('f', 69, 3.14);
  CIDType.printValues();

  MultiType<int, string, bool> intStringBool(10, "COOL!", true);
  intStringBool.printValues();

  return 0;
} 
