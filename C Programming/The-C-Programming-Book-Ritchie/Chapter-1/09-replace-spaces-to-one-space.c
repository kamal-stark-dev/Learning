#include <stdio.h>

int main() {
  int ch;
  int prev_blank = 0;

  while ((ch = getchar()) != EOF) {
    if (ch == ' ') {
      if (prev_blank == 0) { // if it's the first space 
        putchar(ch);
        prev_blank = 1;
      }
    }
    else {
      putchar(ch);
      prev_blank = 0;
    }
  }

  return 0;
}

/*
// my first take
#include <stdio.h>

#define SPACE ' '

int main() {
  int ch;
  while ((ch = getchar()) != EOF) {
    if (ch == SPACE) {
      while ((ch = getchar()) != EOF) {
        if (ch != SPACE) break;
      }
      putchar(SPACE);
    }
    if (ch != EOF)
      putchar(ch);
  }

  return 0;
}
*/
