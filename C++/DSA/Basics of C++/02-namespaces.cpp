#include <iostream>

// creating own namespace
namespace Mine {
    double pi = 6.28;
}

// using namespace std; --> means that all the default cases will be considered the standard case (std).

int main() {
    double pi = 3.14;

    std::cout << "Default Case    : " << pi << std::endl;

    std::cout << "Using Namespace : " << Mine::pi << std::endl;

}