#include <stdio.h>
#include <stdint.h> // for uint8_t

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    if (src == NULL)
    {
        perror("Error opening source file.");
        return 2;
    }

    FILE *dst = fopen(argv[2], "wb");
    if (dst == NULL)
    {
        perror("Error opening destination file.");
        return 2;
    }

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(src);
    fclose(dst);

    printf("File copied succesfully!\n");

    return 0;
}

// usage: ./cp.c source.txt destination.txt (you can also copy images with it)