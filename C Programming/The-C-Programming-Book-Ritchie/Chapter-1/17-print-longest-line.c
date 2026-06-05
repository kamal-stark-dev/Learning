#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len, max_len;
  char line[MAXLINE];
  char longest[MAXLINE];

  max_len = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    if (len > max_len) {
      max_len = len;
      copy(longest, line);
    }
  if (max_len > 0)
    printf("Length: %d\nLongest: %s", max_len, longest);
  
  return 0;
}

int getline(char s[], int lim) {
  int ch, i;
  for (i = 0; i < lim - 1 && (ch = getchar()) != EOF && ch != '\n'; i++) 
    s[i] = ch;
  if (ch == '\n') {
    s[i] = ch;
    i++;
  }
  s[i] = '\0'; // adding end of file
  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}
