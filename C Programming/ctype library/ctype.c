#include <stdio.h>
#include <ctype.h>

// The ctype library provides functions for working with characters

void alnum(char c);
void alpha(char c);

int main()
{
    // isalnum() - a function which tells if a char is alphanumeric (a-z, A-Z or 0-9)
    printf("isalnum():\n");

    alnum('a'); // true
    alnum('Z'); // true
    alnum('8'); // true
    alnum('&'); // false
    printf("\n");

    // isalpha() - tells if a character is an alphabet or not
    printf("isalpha():\n");

    alpha('a'); // true
    alpha('Z'); // true
    alpha('5'); // false
    alpha('%'); // false
    printf("\n");

    // iscntrl() - the is control function tells if a character is printable or not, it's true if it can't be printed
    printf("iscntrl():\n");

    if (iscntrl('\n'))
        printf("true\n");
    else
        printf("false\n");

    if (iscntrl('$'))
        printf("true\n");
    else
        printf("false\n");
    printf("\n");

    // isdigit() - it tells whether a character is a number or not
    printf("isdigit():\n");

    if (isdigit('5'))
        printf("true\n");
    else
        printf("false\n");

    if (isdigit('I'))
        printf("true\n");
    else
        printf("false\n");
    printf("\n");

    // islower() and isupper() - both functions tell if a character is lower or higher respectively
    printf("islower() & isupper():\n");

    if (islower('i'))
        printf("true\n");
    else
        printf("false\n");

    if (islower('I'))
        printf("true\n");
    else
        printf("false\n");
    printf("\n");

    if (isupper('K'))
        printf("true\n");
    else
        printf("false\n");

    if (isupper('k'))
        printf("true\n");
    else
        printf("false\n");

    printf("\n");

    // ispunct() - tells if a char is a puncuation or not
    printf("ispunct():\n");

    if (ispunct('"'))
        printf("true\n");
    else
        printf("false\n");

    if (ispunct('-'))
        printf("true\n");
    else
        printf("false\n");

    if (ispunct('k'))
        printf("true\n");
    else
        printf("false\n");
    printf("\n");

    // isspace() - tells is a char is a whitespace or not
    printf("isspace():\n");

    if (isspace(' '))
        printf("true\n");
    else
        printf("false\n");

    if (isspace('\t'))
        printf("true\n");
    else
        printf("false\n");

    if (isspace('\n'))
        printf("true\n");
    else
        printf("false\n");

    if (isspace('K'))
        printf("true\n");
    else
        printf("false\n");

    printf("\n");

    // isxdigit() - tells if a char is hex digit or not (0-9, a-f and A-F)
    printf("isxdigit():\n");

    if (isxdigit('A'))
        printf("true\n");
    else
        printf("false\n");

    if (isxdigit('G'))
        printf("true\n");
    else
        printf("false\n");

    printf("\n");

    // toupper() and tolower() - converts the char to it's respective upper or lower case.
    printf("toupper() & tolower():\n");

    char a = 'A';

    printf("%c\n", tolower(a));

    char b = 'b';

    printf("%c\n", toupper(b));

    // it'll do nothing if a character doesn't have it's respective lower/upper case.

    char c = '$';

    printf("%c", tolower(c));

    return 0;
}

void alnum(char c)
{
    if (isalnum(c))
        printf("true\n");
    else
        printf("false\n");
}

void alpha(char c)
{
    if (isalpha(c))
        printf("true\n");
    else
        printf("false\n");
}