#include <stdio.h>

/*
  print Fahrenheit-Celsius table
    for fahr = 0, 20, 40, ..., 300
*/

int main() {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    /* we didn't use 5/9 as integer division truncates any fractional part making 5/9 = 0 -> so all celsius values would become 0 that way */
    printf("%3d\t%3d\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}
