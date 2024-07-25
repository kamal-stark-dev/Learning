
// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser

#include <stdio.h>
#include <string.h>

const char COW[][100] = {
    "     \\   ^__^",
    "      \\  (oo)\\________",
    "         (__)\\        )\\/\\",
    "              ||----w |",
    "              ||     ||",
};

void print_message(int length, char message[]);
void print_cow();

int main(int argc, char *argv[])
{

    printf("Enter a message: ");
    char message[100];
    fgets(message, sizeof(message), stdin);

    int length = strlen(message);

    print_message(length, message);

    print_cow();

    return 0;
}

void print_message(int length, char message[])
{
    message[strcspn(message, "\n")] = '\0'; // Remove the newline character
    printf("\n__");
    for (int i = 0; i < length; i++)
    {
        printf("_");
    }
    printf("__");

    printf("\n| %s |", message);

    printf("\n--");
    for (int i = 0; i < length; i++)
    {
        printf("-");
    }
    printf("--\n");
}

void print_cow()
{
    for (int i = 0, l = 5; i < l; i++)
    {
        printf("%s\n", COW[i]);
    }
}
