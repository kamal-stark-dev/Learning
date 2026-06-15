#include <stdio.h>

// USAGE: gcc 02-static-global-variable.c globals.c -o static-globals

/*
headers.c file contains the following code
```c
int global_1 = 69;
static int global_2 = 67;
```
we ca access `global_1` by using the `extern` keyword, as global variables have `external linkage`.

BUT if we define a global variable with `static` then that variable will be visible in that file only (can't be accessed in other files.)

> This is called `internal linkage`.
*/

extern int global_1;
// extern int global_2;

int main() {
  printf("global_1: %d\n", global_1);
  // printf("global_2: %d\n", global_2); // linker error: undefined reference to `global_2'

  return 0;
}

/*
Why use static globals?
> Encapsulation.

```c
static int counter = 0;

void increment() {
  counter++;
}
```
NOTE: Now any other file can't directly modify the counter global variable.
*/
