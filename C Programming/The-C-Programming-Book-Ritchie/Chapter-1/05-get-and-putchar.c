#include <stdio.h>

/*
Pseudocode:
read a character
  while (character is not end-of-file indicator)
    output the character just read 
    read a character 
*/

int main() {
  int c;
  while ((c = getchar()) != EOF) {
    putchar(c);
  }

  printf("EOF: %d\n", c);

  return 0;
}
