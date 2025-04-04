#include <stdio.h>
#include <stdint.h> // for uint8_t

/*
uint8_t
    -> u stands for unsigned (positive only)
    -> int is for integer type
    -> 8 is the number of bytes
    -> _t tells that this is its own type (convention)
*/

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./isPDF <file_name.type>\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        perror("Error opening the file.");
        return 1;
    }

    uint8_t buffer[4];
    int blocks_read = fread(buffer, 1, 4, f); // read 4 bytes to buffer 1 byte at a time from file

    // for a PDF the first four bytes should be 37 80 68 70
    uint8_t pdfBytes[4] = {37, 80, 68, 70};

    int isPDF = 1;
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != pdfBytes[i])
        {
            isPDF = 0;
            break;
        }
    }

    if (isPDF)
    {
        printf("The file \"%s\" is indeed a PDF.\n", filename);
    }
    else
    {
        printf("The file \"%s\" is not a PDF.\n", filename);
    }

    printf("Blocks read: %i\n", blocks_read);

    return 0;
}