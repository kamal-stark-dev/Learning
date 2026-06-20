#include <stdio.h>

int main() {
  int n = 5;
  char pattern = 'A';
  
  for (int i = 0; i < n; i++) {
    
    for (int j = 0; j < i + 1; j++)
      printf("%c", pattern);

    pattern++;
    printf("\n");
  }

  return 0;
}
