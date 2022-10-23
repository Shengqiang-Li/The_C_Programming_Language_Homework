#include<stdio.h>

/* concat string */

void strcat(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0') i++;
    while ( (s[i++] = t[j++]) != '\0');
}

int main() {
    char s[10] = "12345";
    char t[5] = "4321";
    strcat(s, t);
    printf("cat 12345 and %s: %s\n", t, s);
    return 0;
}