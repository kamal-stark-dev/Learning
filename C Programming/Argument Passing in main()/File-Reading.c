#include <stdio.h>

#define LINE_BUFFER 100

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file;
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("File not found\n");
        return 1;
    }
    else
    {
        // Read the file
        char buffer[LINE_BUFFER];
        while (fgets(buffer, LINE_BUFFER, file) != NULL)
            printf("%s", buffer);
    }

    fclose(file);

    return 0;
}