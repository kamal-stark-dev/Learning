#include <stdio.h>

#define MAXLEN 1000

int getline(char line[]);
void reverse_line(char line[], int len);

int main() {
  char line[MAXLEN];
  
  int len;
  while ((len = getline(line)) > 0) {
    reverse_line(line, len);
    printf("%s", line);
  }

  return 0;
}

int getline(char line[]) {
  int ch, i;
  for (i = 0; i < MAXLEN - 1 && (ch = getchar()) != EOF && ch != '\n'; ++i) 
    line[i] = ch;
  if (ch == '\n') {
    line[i] = ch;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void reverse_line(char line[], int len) {
  if (len <= 2) return; // len 2 is essentially len 1 as '\0' will stay at the end always
  
  // 0 1 2 3 4 5 6
  // h e l l o ! \0

  int left = 0, right = len - 2;
  while (left < right) {
    char temp = line[left];
    line[left] = line[right];
    line[right] = temp;
    
    ++left;
    --right;
  }
}
