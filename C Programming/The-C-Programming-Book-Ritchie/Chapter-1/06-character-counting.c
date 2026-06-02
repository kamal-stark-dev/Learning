#include <stdio.h>

int main() {
  long count;

  count = 0;
  while (getchar() != EOF) {
    ++count;
  }
  printf("Character Count: %ld\n", count);

  /*
  // we could also write this using for loop like this:

  double count;
  for (count = 0; getchar() != EOF; count++)
    ; // null statement (as for loops requires to have a body)
  printf("Character Count: %.0f\n", count); 
  */

  return 0;
}
