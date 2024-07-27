#include <stdio.h>

int main(void)
{
    int change;
    int penny = 0, nickel = 0, dime = 0, quarter = 0;

    // input change value
    do
    {
        printf("Change owed: ");
        scanf("%d", &change);
    } while (change < 0);

    while (change >= 25)
    {
        quarter++;
        change -= 25;
    }

    while (change >= 10)
    {
        dime++;
        change -= 10;
    }

    while (change >= 5)
    {
        nickel++;
        change -= 5;
    }

    while (change >= 1)
    {
        penny++;
        change -= 1;
    }

    // printf("Quarter: %d\nDime: %d\nNickel: %d\nPenny: %d\n", quarter, dime, nickel, penny);
    printf("%d\n", quarter + dime + nickel + penny);
}
