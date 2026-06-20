#include <stdio.h>

int min(int a, int b) {
  return (a < b) ? a : b;
}

int main() {
  int n = 5;

  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      int top = i;
      int left = j;
      int last_index = (2 * n - 1) - 1; // or (2 * n - 2)
      int bottom = last_index - i;
      int right = last_index - j;

      int minDist = min(min(top, bottom), min(left, right));
      printf("%d ", (n - minDist));
    }
    printf("\n");
  }

  return 0;
}
