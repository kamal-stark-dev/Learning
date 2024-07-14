#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid number of arguments.\nUsage: %s <integer>", argv[0]);
        return -1;
    }

    int number = atoi(argv[1]);

    printf("Factorial of %d is: %d\n", number, factorial(number));

    return 0;
}

int factorial(int number)
{
    if (number == 1) // Base Case - Condition which terminates the recursion
        return 1;
    return factorial(number - 1) * number;
}