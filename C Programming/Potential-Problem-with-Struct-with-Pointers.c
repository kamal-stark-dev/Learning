#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
} PointerStruct;

void printPointerStruct(PointerStruct p)
{
    for (int i = 0; i < 2; i++)
    {
        printf("p[%d] = %d\n", i, p.array[i]);
    }
}

int main()
{
    PointerStruct p1;
    p1.array = (int *)malloc(sizeof(int) * 2);

    PointerStruct p2;
    p2.array = (int *)malloc(sizeof(int) * 2);

    p1.array[0] = 1;
    p1.array[1] = 2;

    p2.array[0] = 6;
    p2.array[1] = 9;

    printf("AT START:\n");

    printf("p1:\n");
    printPointerStruct(p1);
    printf("\np2:\n");
    printPointerStruct(p2);

    // ---------------------------- //
    p1 = p2;

    printf("\nAFTER P1 = P2:");

    printf("\np1:\n");
    printPointerStruct(p1);
    printf("\np2:\n");
    printPointerStruct(p2);

    p1.array[0] = 111;

    printf("\nCHANGING P1[0] CHANGES P2[0] TOO: ");

    printf("\np1:\n");
    printPointerStruct(p1);
    printf("\np2:\n");
    printPointerStruct(p2);

    printf("\nTHIS HAPPENS BECAUSE WHEN COPYING P2 CONTENTS TO P1 WE ARE COPYING THE POINTER TO THE DYNAMIC ARRAY AS STRUCTURE CONTAINS POINTER.");

    return 0;
}

/* OUTPUT:
AT START:
p1:
p[0] = 1
p[1] = 2

p2:
p[0] = 6
p[1] = 9

AFTER P1 = P2:
p1:
p[0] = 6
p[1] = 9

p2:
p[0] = 6
p[1] = 9

CHANGING P1[0] CHANGES P2[0] TOO:
p1:
p[0] = 111
p[1] = 9

p2:
p[0] = 111
p[1] = 9

THIS HAPPENS BECAUSE WHEN COPYING P2 CONTENTS TO P1 WE ARE COPYING THE POINTER TO THE DYNAMIC ARRAY AS STRUCTURE CONTAINS POINTER.
*/