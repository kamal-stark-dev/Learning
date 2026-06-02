#include <stdio.h>

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = 0;
  printf("Fahr   Celcius\n");
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%4.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}
