#include <stdio.h>

float fahr_to_celsius(float fahr);
float celsius_to_fahr(float celsius);

int main() {
  float fahr = 100;
  printf("%.1fF = %.1fC\n", fahr, fahr_to_celsius(fahr));

  float celsius = 100;
  printf("%.1fC = %.1fF\n", celsius, celsius_to_fahr(celsius));

  return 0;
}

float fahr_to_celsius(float fahr) {
  return (5.0 / 9.0) * (fahr - 32);
}

float celsius_to_fahr(float celsius) {
  return (9.0 / 5.0) * celsius + 32;
}
