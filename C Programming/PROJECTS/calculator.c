#include <math.h>
#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);
int power(int a, int b);

int main(void)
{
    int choice, a, b;
    do
    {
        printf("1. Add\t2. Sub\t3. Mul\t4. Div\t5. Mod\t6. Pow\t0. Exit\n");
        printf("Select number of operation you want to perform: ");
        scanf("%d", &choice);

        printf("Enter num 1: ");
        scanf("%d", &a);

        printf("Enter num 2: ");
        scanf("%d", &b);

        switch (choice)
        {
        case 1:
            printf("Sum: %i\n", add(a, b));
            break;
        case 2:
            printf("Sub: %i\n", sub(a, b));
            break;
        case 3:
            printf("Mul: %i\n", mul(a, b));
            break;
        case 4:
            printf("Div: %i\n", div(a, b));
            break;
        case 5:
            printf("Mod: %i\n", mod(a, b));
            break;
        case 6:
            printf("Pow: %d\n", power(a, b));
            break;
        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Enter a valid choice!!\n");
            break;
        }
    } while (choice != 7);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return a / b;
}

int mod(int a, int b)
{
    return a % b;
}

int power(int a, int b)
{
    return pow(a, b);
}