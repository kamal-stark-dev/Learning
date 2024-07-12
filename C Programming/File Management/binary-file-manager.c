#include <stdio.h>
#include <stdlib.h>

#define BINARY_READ "rb"
#define BINARY_WRITE "wb"

int main()
{
    FILE *bin_file = fopen("binary-file.bin", BINARY_WRITE);

    if (bin_file == NULL)
    {
        printf("Error opening file\n");
        exit(-1);
    }

    int integerNumber = 20;
    fwrite(&integerNumber, sizeof(int), 1, bin_file);

    double doubleNumber = 25.75;
    fwrite(&doubleNumber, sizeof(double), 1, bin_file);

    fclose(bin_file);

    bin_file = fopen("binary-file.bin", BINARY_READ);

    if (bin_file == NULL)
    {
        printf("Error opening file\n");
        exit(-1);
    }

    int readNumber;

    fread(&readNumber, sizeof(int), 1, bin_file);

    double readDoubleNumber;

    fread(&readDoubleNumber, sizeof(double), 1, bin_file);

    printf("Number read from file: %d\n", readNumber);

    printf("Double number read from file: %f\n", readDoubleNumber);

    fclose(bin_file);

    return 0;
}