#include <stdio.h>

int main() {
  int n = 5;

  for (int i = 0; i < n; i++) {
    // print nums
    for (int j = 0; j < i + 1; j++)
      printf("%d", j + 1);

    // print spaces 
    for (int j = 0; j < 2 * (n - i - 1); j++)
      printf(" ");
    

    // print reverse nums
    for (int j = 0; j < i + 1; j++)
      printf("%d", i + 1 - j);
    
    printf("\n");
  }

  return 0;
}
