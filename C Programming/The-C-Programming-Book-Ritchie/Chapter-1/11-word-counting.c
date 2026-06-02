#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int ch, state;
  long char_count, word_count, line_count;

  state = OUT;
  char_count = word_count = line_count = 0;
  while ((ch = getchar()) != EOF) {
    ++char_count;

    if (ch == '\n') 
      ++line_count;
    
    if (ch == ' ' || ch == '\n' || ch == '\t')
      state = OUT;

    else if (state == OUT) {
      state = IN;
      ++word_count;
    }
  }

  printf("Lines Count: %ld\n", line_count);
  printf("Words Count: %ld\n", word_count);
  printf("Chars Count: %ld\n", char_count);

  return 0;
}

