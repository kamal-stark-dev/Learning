#include <stdio.h>
#include <stdbool.h>

int main()
{
    FILE *fileWrite;

    // opening a file
    fileWrite = fopen("io.txt", "w"); // other modes: r, w, a, r+, w+, a+, rb, wb, ab, r+b, w+b, a+b

    // writing to a file
    fputs("Hello, World with fputs!!\n\n", fileWrite);

    // another way to write to a file
    fprintf(fileWrite, "Hello, World with fprintf!!\n");

    char message[] = "It's COOL right?";
    fprintf(fileWrite, "You can use formatting in fprintf: %s\n\n", message);

    // closing a file
    fclose(fileWrite);

    // reading from a file and also appending data to it

    FILE *fileAppend;

    fileAppend = fopen("io.txt", "a+");

    int input;
    // appending data to a file
    while (true)
    {
        printf("Enter a number (-1 quits): ");
        scanf("%d", &input);

        if (input == -1)
            break;
        else
            fprintf(fileAppend, "%d\n", input);
    }

    fclose(fileAppend);

    // reading from a file
    FILE *fileRead;

    fileRead = fopen("io.txt", "r");

    char buffer[100];

    while (fgets(buffer, 100, fileRead) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fileRead);

    return 0;
}