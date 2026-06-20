#include <iostream>
using namespace std;

template<typename T1, typename T2 = double, typename T3 = string>
class DefaultValues {
public:
  T1 x;
  T2 y;
  T3 z;

  DefaultValues(T1 val1, T2 val2, T3 val3) : x(val1), y(val2), z(val3) {}

  void printValues() {
    cout << "X: " << x << "\tY: " << y << "\tZ: " << z << "\n";
  } 
};

int main() {
  DefaultValues<char> charObj('A', 100.00, "Excellent");
  charObj.printValues();

  DefaultValues<string, int, bool> charIntBoolObj("Nice", 69, false);
  charIntBoolObj.printValues();

  return 0;
}
