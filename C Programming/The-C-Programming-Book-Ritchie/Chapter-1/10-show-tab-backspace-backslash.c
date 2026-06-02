#include <stdio.h>

int main() {
  int ch;
  while ((ch = getchar()) != EOF) {
    if (ch == '\t') 
      printf("\\t");
    else if (ch == '\b')
      printf("\\b");
    else if (ch == '\\')
      printf("\\\\");
    else 
      putchar(ch);
  }

  return 0;
}
