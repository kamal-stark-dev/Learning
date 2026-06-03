#include <stdio.h>

int main() {
  int ch, space_count, char_count;
  int digit_count[10];

  space_count = char_count = 0;
  for (int i = 0; i < 10; ++i)
    digit_count[i] = 0;

  while ((ch = getchar()) != EOF) {
    if (ch >= '0' && ch <= '9')
      ++digit_count[ch - '0'];
    else if (ch == ' ' || ch == '\n' || ch == '\t')
      ++space_count;
    else 
      ++char_count;
  }

  printf("digits = ");
  for (int i = 0; i < 10; i++) {
    printf(" %d", digit_count[i]);
  }
  printf(", white space = %d, char = %d\n", 
         space_count, char_count);

  return 0;
}
