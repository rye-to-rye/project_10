#include <stdio.h>
#include <ctype.h>
#include "read_line.h"

int read_line(char str[], int n) //read in a string
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n' && ch != EOF) {
    if (i < n)
      i++;
    str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}
