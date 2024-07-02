#include <stdio.h>  // for standard input/output
#include <stdlib.h> // for functions like malloc() and free()
#include <string.h> // for functions like strlen(), strcpy(), and strcat()
#include <ctype.h>  // for function like tolower()

// Function prototypes
int BinaryToDecimal(const char *binary);
char *DecimalToBinary(const int decimal);
char *HexToBinary(const char *hex);
char *BinaryToHex(const char *binary);
int HexToDecimal(const char *hex);
char *DecimalToHex(const int decimal);

int main()
{
    // Test HexToDecimal
    char hex[] = "1A3";
    int decimal = HexToDecimal(hex);
    if (decimal >= 0)
    {
        printf("\nHexadecimal to Decimal Conversion:\n");
        printf("Hexadecimal: %s\n", hex);
        printf("Decimal: %d\n\n", decimal);
    }
    else
    {
        printf("Error converting hexadecimal to decimal.\n\n");
    }

    // Test DecimalToHex
    int decimalNumber = 419;
    char *hexResult = DecimalToHex(decimalNumber);
    if (hexResult != NULL)
    {
        printf("Decimal to Hexadecimal Conversion:\n");
        printf("Decimal: %d\n", decimalNumber);
        printf("Hexadecimal: %s\n\n", hexResult);
        free(hexResult); // Free allocated memory for the hexadecimal string
    }
    else
    {
        printf("Error converting decimal to hexadecimal.\n\n");
    }

    // Test BinaryToDecimal
    char binary[] = "1001010101000";
    int decimalFromBinary = BinaryToDecimal(binary);
    printf("Binary to Decimal Conversion:\n");
    printf("Binary: %s\n", binary);
    printf("Decimal: %d\n\n", decimalFromBinary);

    // Test DecimalToBinary
    int decimalNumberForBinary = 419;
    char *binaryResult = DecimalToBinary(decimalNumberForBinary);
    if (binaryResult != NULL)
    {
        printf("Decimal to Binary Conversion:\n");
        printf("Decimal: %d\n", decimalNumberForBinary);
        printf("Binary: %s\n\n", binaryResult);
        free(binaryResult); // Free allocated memory for the binary string
    }
    else
    {
        printf("Error converting decimal to binary.\n\n");
    }

    // Test HexToBinary
    char hexToBinary[] = "1A3";
    char *binaryFromHex = HexToBinary(hexToBinary);
    if (binaryFromHex != NULL)
    {
        printf("Hexadecimal to Binary Conversion:\n");
        printf("Hexadecimal: %s\n", hexToBinary);
        printf("Binary: %s\n\n", binaryFromHex);
        free(binaryFromHex); // Free allocated memory for the binary string
    }
    else
    {
        printf("Error converting hexadecimal to binary.\n\n");
    }

    // Test BinaryToHex
    char binaryToHex[] = "1001010101000";
    char *hexFromBinary = BinaryToHex(binaryToHex);
    if (hexFromBinary != NULL)
    {
        printf("Binary to Hexadecimal Conversion:\n");
        printf("Binary: %s\n", binaryToHex);
        printf("Hexadecimal: %s\n\n", hexFromBinary);
        free(hexFromBinary); // Free allocated memory for the hexadecimal string
    }
    else
    {
        printf("Error converting binary to hexadecimal.\n\n");
    }

    return 0;
}

int BinaryToDecimal(const char *binary)
{
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);

    for (int i = len - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

char *DecimalToBinary(const int decimal)
{
    // Convert decimal to binary
    int copy = decimal;
    char binary_str[32]; // Buffer to hold binary string
    int index = 0;

    if (copy == 0)
    {
        binary_str[index++] = '0';
    }

    while (copy > 0)
    {
        binary_str[index++] = (copy % 2) ? '1' : '0';
        copy /= 2;
    }
    binary_str[index] = '\0';

    // Reverse the binary string
    for (int i = 0; i < index / 2; i++)
    {
        char temp = binary_str[i];
        binary_str[i] = binary_str[index - 1 - i];
        binary_str[index - 1 - i] = temp;
    }

    char *binary = (char *)malloc(index + 1);
    if (binary == NULL)
    {
        // Handle memory allocation failure
        return NULL;
    }
    strcpy(binary, binary_str);

    return binary;
}

char *HexToBinary(const char *hex)
{
    int len = strlen(hex);

    char *binary = (char *)malloc(4 * len + 1); // +1 for null terminator '\0'
    if (binary == NULL)
    {
        // Handle memory allocation failure
        return NULL;
    }
    binary[0] = '\0'; // Initialize to an empty string

    const char HEX_BINARY_CODES[][2][5] = {
        {"0", "0000"},
        {"1", "0001"},
        {"2", "0010"},
        {"3", "0011"},
        {"4", "0100"},
        {"5", "0101"},
        {"6", "0110"},
        {"7", "0111"},
        {"8", "1000"},
        {"9", "1001"},
        {"a", "1010"},
        {"b", "1011"},
        {"c", "1100"},
        {"d", "1101"},
        {"e", "1110"},
        {"f", "1111"},
    };

    for (int j = 0; j < len; j++)
    {
        for (int i = 0; i < 16; i++)
        {
            if (tolower(hex[j]) == HEX_BINARY_CODES[i][0][0])
            {
                strcat(binary, HEX_BINARY_CODES[i][1]);
                break;
            }
        }
    }
    return binary;
}

char *BinaryToHex(const char *binary)
{
    int len = strlen(binary);
    int hex_len = (len % 4 == 0) ? len / 4 : len / 4 + 1;
    char *hex = (char *)calloc(hex_len + 1, sizeof(char));
    if (hex == NULL)
    {
        // Handle memory allocation failure
        return NULL;
    }
    hex[0] = '\0';

    char temp[5]; // Enough space to hold 4 characters plus the null terminator

    const char HEX_BINARY_CODES[][2][5] = {
        {"0", "0000"},
        {"1", "0001"},
        {"2", "0010"},
        {"3", "0011"},
        {"4", "0100"},
        {"5", "0101"},
        {"6", "0110"},
        {"7", "0111"},
        {"8", "1000"},
        {"9", "1001"},
        {"A", "1010"},
        {"B", "1011"},
        {"C", "1100"},
        {"D", "1101"},
        {"E", "1110"},
        {"F", "1111"},
    };

    for (int i = len - 1; i >= 0; i -= 4)
    {
        int start = (i - 3 >= 0) ? i - 3 : 0;
        int length = (i - 3 >= 0) ? 4 : i + 1;

        strncpy(temp, &binary[start], length);
        temp[length] = '\0';

        // Pad the binary string to 4 characters if necessary
        if (length < 4)
        {
            char padded_temp[5] = "0000";
            strncpy(&padded_temp[4 - length], temp, length);
            strcpy(temp, padded_temp);
        }

        for (int j = 0; j < 16; j++)
        {
            if (strcmp(temp, HEX_BINARY_CODES[j][1]) == 0)
            {
                char hex_digit[2];
                strcpy(hex_digit, HEX_BINARY_CODES[j][0]);
                strcat(hex, hex_digit);
                break;
            }
        }
    }

    // Reverse the hex string to get the correct order
    int hex_str_len = strlen(hex);
    for (int i = 0; i < hex_str_len / 2; i++)
    {
        char temp_char = hex[i];
        hex[i] = hex[hex_str_len - 1 - i];
        hex[hex_str_len - 1 - i] = temp_char;
    }

    return hex;
}

int HexToDecimal(const char *hex)
{
    // Convert hexadecimal to binary
    char *binary = HexToBinary(hex);
    if (binary == NULL)
    {
        // Handle memory allocation failure
        return -1;
    }

    // Convert binary to decimal
    int result = BinaryToDecimal(binary);

    // Free the allocated binary string
    free(binary);

    return result;
}

char *DecimalToHex(const int decimal)
{
    // Convert decimal to binary
    char *binary = DecimalToBinary(decimal);

    // Convert binary to hexadecimal
    char *hex = BinaryToHex(binary);

    // Free the allocated binary string
    free(binary);

    return hex;
}

/*
SAMPLE INPUT:
Hexadecimal to Decimal Conversion:
Hexadecimal: 1A3
Decimal: 419

Decimal to Hexadecimal Conversion:
Decimal: 419
Hexadecimal: 1A3

Binary to Decimal Conversion:
Binary: 1001010101000
Decimal: 419

Decimal to Binary Conversion:
Decimal: 419
Binary: 110100011

Hexadecimal to Binary Conversion:
Hexadecimal: 1A3
Binary: 000110100011

Binary to Hexadecimal Conversion:
Binary: 1001010101000
Hexadecimal: 4A8
*/