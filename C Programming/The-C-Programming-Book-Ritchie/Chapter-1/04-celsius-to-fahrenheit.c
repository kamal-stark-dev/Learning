#include <stdio.h>

int main() {
  float celsius, fahr;
  
  for (celsius = 0; celsius <= 300; celsius = celsius + 20) {
    fahr = ((9.0 / 5.0) * celsius) + 32;
    printf("%4.0f\t%6.1f\n", celsius, fahr);
  }

  return 0;
}
