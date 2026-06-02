#include <stdio.h>

int main() {
  int ch;
  long spaces, tabs, newlines;

  spaces = tabs = newlines = 0;
  
  while ((ch = getchar()) != EOF) {
    if (ch == ' ') ++spaces;
    else if (ch == '\t') ++tabs;
    else if (ch == '\n') ++newlines;
  }

  printf("Spaces Count: %ld\n", spaces);
  printf("Tabs Count: %ld\n", tabs);
  printf("New Lines Count: %ld\n", newlines);

  return 0;
}
