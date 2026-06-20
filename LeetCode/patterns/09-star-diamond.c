#include <stdio.h>

int main() {
  int n = 5;

  for (int i = 0; i < n; i++) {
    // print spaces
    for (int j = 0; j < n - i - 1; j++) 
      printf(" ");

    // print stars
    for (int j = 0; j < (2 * i) + 1; j++)
      printf("*");

    printf("\n");
  }

  for (int i = 0; i < n; i++) {
    // print spaces
    for (int j = 0; j < i; j++)
      printf(" ");

    // print stars
    for (int j = 0; j < (2 * (n - i - 1)) + 1; j++) 
      printf("*");

    printf("\n");
  }

  return 0;
}
