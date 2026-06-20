#include <stdio.h>

int main() {
  int n = 5;

  for (int i = 0; i < n; i++) {
    char pattern = 'A';
    
    for (int j = 0; j < i + 1; j++)
      printf("%c", pattern++);
    
    printf("\n");
  }

  return 0;
}
