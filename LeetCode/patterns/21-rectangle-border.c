#include <stdio.h>

int main() {
  int n = 5;

  // top border
  for (int i = 0; i < n; i++)
    printf("* ");
  printf("\n");

  // side borders
  for (int i = 0; i < n - 2; i++) {
    printf("* ");

    for (int j = 0; j < n - 2; j++) 
      printf("  ");

    printf("*\n");
  }

  // bottom border
  for (int i = 0; i < n; i++)
    printf("* ");
  printf("\n");

  return 0;
}
