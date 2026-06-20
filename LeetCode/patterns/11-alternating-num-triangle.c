#include <stdio.h>

int main() {
  int n = 5;
  int pattern = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      printf("%d", pattern);
      pattern = pattern ^ 1;
    }
    printf("\n");
  }

  return 0;
}
