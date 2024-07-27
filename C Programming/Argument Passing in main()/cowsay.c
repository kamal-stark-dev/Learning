
// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser

#include <stdio.h>
#include <string.h>

const char COWS[][5][40] = {
    {
        "     \\   ^__^",
        "      \\  (oo)\\________",
        "         (__)\\        )\\/\\",
        "              ||----w |",
        "              ||     ||",
    },
    {
        "     \\   ^__^",
        "      \\  ($$)\\________",
        "         (__)\\        )\\/\\",
        "              ||----w |",
        "              ||     ||",
    },
    {
        "     \\   ^__^",
        "      \\  (xx)\\________",
        "         (_ )\\        )\\/\\",
        "           U  ||----w |",
        "              ||     ||",
    },
    {
        "     \\   ^__^",
        "      \\  (..)\\________",
        "         (__)\\        )\\/\\",
        "              ||----w |",
        "              ||     ||",
    }};

const char COW_LIST[][10] = {"-default", "-money", "-ded", "-amazed"};

void print_message(char *message);
void print_cow(char *argument);

int main(int argc, char *argv[])
{
    char message[100];

    // printf("Enter a message: ");
    // fgets(message, sizeof(message), stdin);

    strcpy(message, argv[2]);

    print_message(message);

    print_cow(argv[1]);

    return 0;
}

void print_message(char *message)
{
    int length = strlen(message);

    message[strcspn(message, "\n")] = '\0'; // Remove the newline character
    printf("\n");
    for (int i = 0; i < length + 4; i++)
    {
        printf("_");
    }

    printf("\n| %s |", message);

    printf("\n");
    for (int i = -4; i < length; i++)
    {
        printf("-");
    }
    printf("\n");
}

void print_cow(char *argument)
{
    for (int i = 0; i < 4; i++)
    {
        if (!strcmp(argument, COW_LIST[i]))
        {
            // printf("%s\n", COW_LIST[i]);
            for (int j = 0, l = 5; j < l; j++)
            {
                printf("%s\n", COWS[i][j]);
            }
        }
    }
}
