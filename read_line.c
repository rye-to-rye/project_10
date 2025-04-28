#include <stdio.h>
#include <ctype.h>
#include "read_line.h"

int read_line(char str[], int n) {
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;  // skip initial whitespace

    if (ch != '\n' && ch != EOF) {  // only save valid character
        str[i++] = ch;
    }

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
