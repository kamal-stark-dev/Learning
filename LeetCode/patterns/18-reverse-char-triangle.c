#include <stdio.h>

int main() {
  int n = 5;
  char base = 'A' + n - 1;

  for (int i = 0; i < n; i++) {
    char pattern = base - i;
    for (int j = 0; j < i + 1; j++) 
      printf("%c", pattern++);

    printf("\n");
  }

  return 0;
}
