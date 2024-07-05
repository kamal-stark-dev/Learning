// Pointers
#include <stdio.h>

typedef struct
{
    int a;
    char b;
    float c;
} Structure;

void printValue(int value)
{
    printf("The value is: %d\n", value);
}

void add(int a, int b)
{
    printf("Addition is %d\n", a + b);
}
void subtract(int a, int b)
{
    printf("Subtraction is %d\n", a - b);
}
void multiply(int a, int b)
{
    printf("Multiplication is %d\n", a * b);
}

int main()
{
    printf("POINTERS: stores the address of a C variable and allows you to manipulate these variables.\n\n");

    int a = 10, *ptr = &a;

    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n\n", &a);

    printf("Value of ptr: %p\n", ptr);
    printf("Address of ptr: %p\n", &ptr);
    printf("Dereferencing value of ptr: %d\n", *ptr);

    printf("\nTYPES OF POINTERS:\n\n");

    printf("1. Integer Pointers: Points to primitive or user defined data types like int, charr, float, structure etc.\n\n");

    char b = 'B';
    char *integerPtr = &b;

    printf("2. Array Pointers: Points to an array, it assigns pointer to the first element of the array.\n\n");

    int arr[5] = {1, 2, 3, 4, 5};
    int *arrayPtr = arr;

    printf("3. Structure Pointers: Points to a structure object. Used in data structures like linked lists, trees etc.\n\n");

    Structure structure = {1, 'A', 3.14};
    Structure *structure_pointer = &structure;

    printf("4. Function Pointers: Points to a function, it's different from others because it doesn't points to the data but to the code of the function itself.\n\n");

    void (*funPtr)(int);
    funPtr = &printValue;

    // invoking the function using ptr
    (*funPtr)(10);

    printf("\nYou can even point funtions to a ptr array.\n\n");

    void (*funPtrArr[])(int, int) = {
        add, subtract, multiply};

    (*funPtrArr[0])(10, 4);
    (*funPtrArr[1])(10, 4);
    (*funPtrArr[2])(10, 4);

    printf("\n5. Double Pointers: We can point a pointer to another pointer, so it stores address of another pointer.\n\n");

    int c = 123;
    int *ptr1 = &c;
    int **ptr2 = &ptr1;

    printf("Value of variable: %d\n", c);
    printf("Address of variable: %p\n\n", &c);

    printf("Value of ptr1 = %p\n", ptr1);
    printf("Dereference of ptr1 = %d\n", *ptr1);
    printf("Address of ptr1 = %p\n\n", &ptr1);

    printf("Value of ptr2 = %p\n", ptr2);
    printf("Dereference of ptr2 = %p\n", *ptr2);
    printf("Double Dereference of ptr2 = %d\n", **ptr2);
    printf("Address of ptr2 = %p\n\n", &ptr2);

    // you can even create multiple pointers pointing to each other -> *p, **p, ***p, ****p, and so on.

    printf("6. Null Pointer: Do not point to any memory location. Recommended to allocate to pointer which are not currently in use.\n\n");

    int *nullPointer = NULL;
    // OR  - nullPointer = NULL;

    printf("7. Void Pointers: Points to the type void. They do not have any associated data type, they are called generic pointers as they can point to any type. One of it's main properties is that they can't be deferenenced.\n\n");

    void *voidPointer;

    printf("8. Wild Pointers: Pointers that have not been initialized with something yet. Can eventually cause a crash and data corruption.");

    // int *ptr;

    printf("9. Constant Pointers: The memory address stored inside the pointer is fixed and cannot be modified after it's defined.\n\n");

    float d = 4.56;
    float *const constPointer = &d;

    printf("10. Pointer to Constant: Points to a constant value which can not be modified. You can access the value but not modify it.\n\n");

    double PI = 3.14159;
    const double *pointerToConst = &PI;

    // *pointerToConst = 4; // error: assignment of read-only location

    printf("END~");
    return 0;
}