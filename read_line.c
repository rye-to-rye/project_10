int read_line(char str[], int n) { 
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;  

    if (ch != '\n' && ch != EOF) {  
        str[i++] = ch;
    }

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
