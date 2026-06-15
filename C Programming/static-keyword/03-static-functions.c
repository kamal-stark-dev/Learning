#include <stdio.h>
#include <math.h>

/*
Static functions are functions that are preceeded with the `static` keyword, and they are only accessible in the current file.

example: the `helper_square` and `helper_sqrt` functions are static so you can't access them using `extern double helper_square(double num);` as this will give a linker error.

Similar to static global variables these functions can not be accessed by any other file.

> Usecase: Creating helper functions that are just for internal implementation.

*/

static double helper_square(double num) {
  return num * num;
}

static double helper_sqrt(double num) {
  return sqrt(num);
}

double find_hypotenuse(double base, double height) {
  double base_sq = helper_square(base);
  double height_sq = helper_square(height);
  return helper_sqrt( base_sq + height_sq );
}

int main() {    
  double base = 3;
  double height = 4;

  printf("Base: %.2lf\n", base);
  printf("Height: %.2lf\n", height);

  printf("Hypotenuse: %.2lf\n", find_hypotenuse(3, 4));
  return 0;
}
