// POINTERS
#include <stdio.h>

typedef struct
{
    int a;
    char b;
    float c;
} Structure;

void printValue(int value);
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void multipleValues(int a, int b, int *sum, int *diff);

int main()
{
    printf("POINTERS: stores the address of a C variable and allows you to manipulate these variables.\n\n");

    int a = 10, *ptr = &a;

    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n\n", &a); // we use %p to show pointer's value

    // scanf("%d", &var_name); // scanf also takes address of a variable
    // scanf("%d", ptr); // this will work same as putting &a

    printf("Value of ptr: %p\n", ptr);
    printf("Address of ptr: %p\n", &ptr);
    printf("Dereferencing value of ptr: %d\n", *ptr);

    printf("\nSIZES OF POINTERS: \n\n");
    printf("Size of int pointer: %lu bytes\n", sizeof(int *));
    // 8 bytes for 64-bit system
    // 4 bytes for 32-bit system
    printf("The size of every pointer is the same, regardless of the data type it points to as it stores the memory address which is same no matter the data type.\n\n");

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

    printf("POINTER ARITHIMETIC: \n\n");

    printf("Refers to legal valid arithemetic operations that can be performed on pointers.\n\n");

    printf("1. Increment and Decrement: \n\n");

    int arr1[] = {1, 2, 3, 4, 5};

    int *ptr3 = arr1;

    printf("Value of ptr3 = %p\n", ptr3);
    printf("Dereference of ptr3 = %d\n", *ptr3);

    ptr3++;
    printf("Value of ptr3 after increment = %p\n", ptr3);
    printf("Dereference of ptr3 after increment = %d\n", *ptr3);

    ptr3--;
    printf("Value of ptr3 after decrement = %p\n", ptr3);
    printf("Dereference of ptr3 after decrement = %d\n", *ptr3);

    printf("\n2. Addition and Subtraction: \n\n");

    int *ptr4 = &arr1[2];

    printf("Value of ptr4 = %p\n", ptr4);
    printf("Dereference of ptr4 = %d\n", *ptr4);

    ptr4 = ptr4 + 2;
    printf("Value of ptr4 after addition = %p\n", ptr4);
    printf("Dereference of ptr4 after addition = %d\n", *ptr4);

    ptr4 = ptr4 - 2;
    printf("Value of ptr4 after subtraction = %p\n", ptr4);
    printf("Dereference of ptr4 after subtraction = %d\n", *ptr4);

    printf("\n3. Pointer Comparison: \n\n");

    int *ptr5 = &arr1[2];
    int *ptr6 = &arr1[4];

    if (ptr5 < ptr6)
    {
        printf("ptr5 is less than ptr6\n");
    }
    else
    {
        printf("ptr5 is greater than ptr6\n");
    }

    printf("\n4. Pointer to Array: \n\n");

    int arr2[5] = {1, 2, 3, 4, 5};
    int *ptr7 = arr2;

    printf("Value of ptr7 = %p\n", ptr7);
    printf("Dereference of ptr7 = %d\n\n", *ptr7);

    printf("USE CASE OF POINTERS: \n\n");

    printf("1. Dynamic Memory Allocation. \n\n");
    printf("2. Accessing Arrays Elements. \n\n");
    printf("3. Return Multiple Values from a Function. \n\n");
    printf("4. Pass by Reference. \n\n");
    printf("5. Implement Data Structures. \n\n");
    printf("6. Locating exact position of memory. \n\n");
    printf("7. In System-Level Programming where memory addresses are useful. \n\n");

    /*
    ADVANTEGES OF POINTERS:

    1. Dynamic Memory Allocation and Deallocation.
    2. An array or structure can be accessed efficiently with pointers.
    3. Useful for accessing memory locations.
    4. Used in complex data structures like linked lists, graphs, trees etc.
    5. Pointers reduces the length of program and aslo reduces the execution time.

    DISADVANTAGES OF POINTERS:

    1. Memory can get corrupted if an incorrect value is provided to pointers.
    2. Pointers can be complex to understand.
    3. Pointers are majorly responsible for memory leaks in C.
    4. Pointers are comparitively slower than variables in c.
    5. Uninitialized pointers might cause segmentation fault.
    */

    printf("END~");

    return 0;
}

// FUNCTIONS DEFINATION

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

void multipleValues(int a, int b, int *sum, int *diff)
{
    *sum = a + b;
    *diff = a - b;
}