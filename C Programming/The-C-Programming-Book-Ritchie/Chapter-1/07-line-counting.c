#include <stdio.h>

int main() {
  int ch;
  long lines;

  /*lines = 0;*/
  /*while ((ch = getchar()) != EOF) {*/
  /*  if (ch == '\n') */
  /*    ++lines;*/
  /*}*/

  for (lines = 0; ch != EOF; ch = getchar()) {
    if (ch == '\n') ++lines;
  }
  printf("Lines Count: %ld\n", lines);

  return 0;
}
