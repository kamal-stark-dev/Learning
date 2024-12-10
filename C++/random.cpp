#include <iostream>
#include <cstdlib>  // random
#include <ctime>

int main() {
    short min = 1;
    short max = 6;

    srand(time(nullptr));
    int roll1 = rand() % (max - min + 1) + min;
    int roll2 = rand() % (max - min + 1) + min;

    std::cout << roll1 << ", " << roll2 << std::endl;

    return 0;
}