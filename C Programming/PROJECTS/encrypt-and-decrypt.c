#include <ctype.h>
#include <stdio.h>

char encipher(char c, int key);
char decipher(char c, int key);

int main(void)
{
    int key = 1;
    char plaintext[100];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // printf("%s", plaintext);

    char ciphertext[100];

    int i;
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        ciphertext[i] = encipher(plaintext[i], key);
    }
    ciphertext[i] = '\0';

    printf("ciphertxt: %s", ciphertext);

    char deciphertext[100];

    for (i = 0; ciphertext[i] != '\0'; i++)
    {
        deciphertext[i] = decipher(ciphertext[i], key);
    }
    deciphertext[i] = '\0';

    printf("decrypted: %s", deciphertext);
}

char encipher(char c, int key)
{

    if (!isalpha(c))
        return c;

    if (isupper(c))
        return ((c - 'A' + key) % 26) + 'A';

    return ((c - 'a' + key) % 26) + 'a';
}

char decipher(char c, int key)
{
    if (!isalpha(c))
        return c;

    if (isupper(c))
        return ((c - 'A' - key) % 26) + 'A';

    return ((c - 'a' - key) % 26) + 'a';
}