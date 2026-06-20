#include <iostream>
using namespace std;

// creates a different variable for each type
template<typename T> constexpr T pi = T(3.1415926535897932385);

int main() {
  cout << "Pi as float: " << pi<float> << "\n";
  cout << "Pi as int: " << pi<int> << "\n";
  cout << "Pi as double: " << pi<double> << "\n";

  return 0;
}
