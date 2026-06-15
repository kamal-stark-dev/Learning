#include <stdio.h>

/*
# Memory Layout of C Program

+-------------------+
| Code / Text       |
+-------------------+
| Initialized       |
| static / global   |
| (.data)           |
+-------------------+
| Uninitialized     |
| static / global   |
| (.bss)            |
+-------------------+
| Heap              |
+-------------------+
| Stack             |
+-------------------+
*/

// Data segment
static int x = 10;

// BSS segment 
static int y; // 0 by default 

static char *ptr; // NULL by default

int main() {
  printf("Default value of y: %d\n", y);
  printf("Default value of ptr: %s\n", ptr);

  return 0;
}

// NOTE: In one line, `static` can either increase the lifetime of a variable or restrict the visibility of a variable or a function depending on where it's used.
