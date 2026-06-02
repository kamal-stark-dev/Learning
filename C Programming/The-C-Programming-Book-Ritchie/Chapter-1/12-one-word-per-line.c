#include <stdio.h>

#define IN   1
#define OUT  0

int main() {
  int ch;
  int in_word = OUT;

  while ((ch = getchar()) != EOF) {
    if (ch == ' ' || ch == '\n' || ch == '\t') {
      if (in_word == IN) {
        putchar('\n');
        in_word = OUT;
      }
    }
    else {
      putchar(ch);
      in_word = IN;
    }
  }

  return 0;
}
