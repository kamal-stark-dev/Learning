#include <stdio.h>

// Is there any method from which you can create a single function which is also generic at a ceratin level and is only of a single line?

// The answer is YES.

// you can simply use it as MARCO in C programming.
// #define add(a, b) (a + b)

#define sum(a, b) _Generic((a), \
    int: sum_int,               \
    float: sum_float,           \
    double: sum_double,         \
    char: sum_char)(a, b)

int sum_int(int a, int b)
{
    return a + b;
}
float sum_float(float a, float b)
{
    return a + b;
}
double sum_double(double a, double b)
{
    return a + b;
}
char sum_char(char a, char b)
{
    return a + b;
}

#define printValue(x) _Generic((x), \
    int: printf("%d\n", x),         \
    float: printf("%f\n", x),       \
    double: printf("%lf\n", x),     \
    char: printf("%c\n", x))

int main()
{
    printf("Sum is: ");
    printValue(sum(10, 20));
}