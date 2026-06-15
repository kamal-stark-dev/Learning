#include <stdio.h>

/*
Static Local Variables:
- gets initialized only once 
- stays until the end of the program
- preserves the value of the variable in between function calls

NOTE: many people get confused and think that they can access this variable outside the function (not true).
1. The scope of the variable is inside the function only.
2. But the lifetime of the variable is for the entire program.
*/

void counter() {
  static int count = 0; // try removing the static keyword
  count++;
  printf("%d\n", count);
}

int main() {
  counter();
  counter();
  counter();

  return 0;
}
