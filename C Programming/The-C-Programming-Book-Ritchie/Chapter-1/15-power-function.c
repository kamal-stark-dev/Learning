#include <stdio.h>

int power(int m, int n);

int main() {
  int i, base;

  base = 2;
  for (i = 0; i <= 10; i++)
    printf("%d^%d = %d\n", base, i, power(base, i));

  return 0;
}

int power(int base, int n) {
  int i, res;

  res = 1;
  for (i = 1; i <= n; i++)
    res = res * base;

  return res;
}
