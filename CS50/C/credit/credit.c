#include <stdio.h>

// Function prototypes
int calculate_digits(long card_number);
int get_first_digits(long card_number, int digits);
int validate_luhn(long card_number, int digits);

int main()
{
    long int card_number;

    // Input from user
    do
    {
        printf("Number: ");
        if (scanf("%ld", &card_number) != 1)
        {
            printf("INVALID\n");
            return 0;
        }
    } while (card_number < 0);

    // Calculate number of digits in card number
    int digits = calculate_digits(card_number);

    // Check digit count
    if (digits != 15 && digits != 16 && digits != 13)
    {
        printf("INVALID\n");
        return 0;
    }

    // Check first digits
    int check = get_first_digits(card_number, digits);
    if (check == -1)
    {
        printf("INVALID\n");
        return 0;
    }

    // Validate the card number using Luhn's Algorithm
    int valid = validate_luhn(card_number, digits);
    if (!valid)
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine and print card type
    switch (check)
    {
    case 1:
        printf("AMEX\n");
        break;
    case 2:
        printf("MASTERCARD\n");
        break;
    case 3:
        printf("VISA\n");
        break;
    default:
        printf("INVALID\n");
    }

    return 0;
}

// Function to calculate number of digits in a card number
int calculate_digits(long card_number)
{
    int num = 0;
    while (card_number > 0)
    {
        card_number /= 10;
        num++;
    }
    return num;
}

// Function to determine card issuer based on first digits
int get_first_digits(long card_number, int digits)
{
    if (digits == 15)
    {
        card_number /= 10000000000000; // Divide by 10^13
        switch (card_number)
        {
        case 34:
        case 37:
            return 1; // AMEX
        default:
            return -1;
        }
    }
    else if (digits == 16)
    {
        card_number /= 100000000000000; // Divide by 10^15
        if (card_number >= 51 && card_number <= 55)
        {
            return 2; // MASTERCARD
        }
        else if (card_number / 10 == 4)
        {
            return 3; // VISA
        }
        else
        {
            return -1;
        }
    }
    else if (digits == 13)
    {
        card_number /= 1000000000000; // Divide by 10^12
        if (card_number == 4)
        {
            return 3; // VISA
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

// Function to validate the card number using Luhn's Algorithm
int validate_luhn(long card_number, int digits) // this function itself is concise and pretty cool
{
    int sum = 0;
    int is_second = 0;

    while (card_number > 0)
    {
        int digit = card_number % 10;

        if (is_second)
        {
            digit *= 2;
            sum += digit / 10 + digit % 10; // this thing is so cool
        }
        else
        {
            sum += digit;
        }

        is_second = !is_second;
        card_number /= 10;
    }

    return (sum % 10 == 0);
}
