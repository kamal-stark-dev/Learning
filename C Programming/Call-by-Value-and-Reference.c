#include <stdio.h>

// call by value and call by reference in C

// Call by value doesn't affect the variable as it creates its copy
void callByValue(int x)
{
    x = 100;
}

// Call by reference takes the variables address and using the indirection (*) operator we can change the vakue of the original variable
void callByReference(int *x)
{
    *x = 100;
}

// Call by value & reference in struct
typedef struct
{
    int x;
    int y;
} Point;

// call by value
void twicePointByValue(Point pt)
{
    pt.x *= 2;
    pt.y *= 2;
}

// call by reference
void twicePointByReference(Point *pt)
{
    pt->x *= 2;
    pt->y *= 2;
}

int main()
{
    int a = 10;

    printf("Value of var: %d\n\n", a);

    callByValue(a);
    printf("Value of var after call by value: %d\n\n", a);

    callByReference(&a); // pass the variable's address not the variable
    printf("Value of var after call by reference: %d\n\n", a);

    // for structure
    Point point = {10, 20};

    printf("Value of point is (%d, %d)\n\n", point.x, point.y);

    twicePointByValue(point);
    printf("Value of point after call by value is (%d, %d)\n\n", point.x, point.y);

    twicePointByReference(&point);
    printf("Value of point after call by reference is (%d, %d)\n\n", point.x, point.y);
}