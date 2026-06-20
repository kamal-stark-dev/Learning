#include <iostream>

// makeing it easy to access specific members of a namespace 
using std::cout;
using std::string;

// creating namespace 
namespace my_namespace {
  int num = 69;
}

namespace my_print {
  void print(string s) {
    std::cout << s;
  }
}
using my_print::print;

// you can use `using` to avoid writing the name of the namespace  
using namespace my_namespace;

// you can rename your namespace 
namespace very_long_namespace {
  int num = 67;
}
namespace vln = very_long_namespace;

// you can nest namespaces 
namespace nested {
  namespace inner_namespace {
    int num = 200;
  }

  int num = 100;
}

// you can also define inner namespaces like this 
namespace nested::inner_namespace_2 {
  // body of namespace 
}

int main() {
  cout << num << "\n";

  // using print from `my_print` namespace without writing the name as we have used `using my_print::print;`
  print("hello, world!\n");

  // using `vln` namespace which is nothing but `very_long_namespace`
  cout << vln::num << "\n";

  // accessing from nested namespaces 
  cout << nested::num << "\n";

  cout << nested::inner_namespace::num << "\n";

  return 0;
}
