#include <stdio.h>

#define BAR_CHAR "#"

int main() {
  // declarations
  int space_count = 0, special_char_count = 0;
  
  int digit_count[10];
  for (int i = 0; i < 10; i++) 
    digit_count[i] = 0;

  int char_count[26];
  for (int i = 0; i < 26; i++) 
    char_count[i] = 0;

  // frequency counting
  int ch;
  while ((ch = getchar()) != EOF) {
    if (ch >= 'A' && ch <= 'Z')
      ch += 'a' - 'A'; // or 32; // making all uppercase characters to lowercase
    if (ch >= 'a' && ch <= 'z') 
      char_count[ch - 'a']++;

    else if (ch >= '0' && ch <= '9')
      digit_count[ch - '0']++;

    else if (ch == ' ' || ch == '\n' || ch == '\t')
        space_count++;

    else 
      special_char_count++;
  } 

  // drawing horizontal histogram
  printf("\n==== HORIZONTAL FREQUENCY HISTOGRAM ====\n\n");
  printf(" : ");
  for (int i = 0; i < space_count; i++) 
    printf(BAR_CHAR);
  printf(" -> %d\n", space_count);

  printf("$: ");
  for (int i = 0; i < special_char_count; i++) 
    printf(BAR_CHAR);
  printf(" -> %d\n", special_char_count);

  for (int i = 0; i < 10; i++) {
    printf("%c: ", '0' + i);
    for (int j = 0; j < digit_count[i]; j++) 
      printf(BAR_CHAR);
    printf(" -> %d\n", digit_count[i]);
  }

  for (int i = 0; i < 26; i++) {
    printf("%c: ", 'a' + i);
    for (int j = 0; j < char_count[i]; j++)
      printf(BAR_CHAR);
    printf(" -> %d\n", char_count[i]);
  }

  return 0;
}
