#include<stdio.h>

/* atoi: convert s to int */
int atoi(char s[]) {
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int main() {
    char s[10] = "123454321";
    printf("string = %s, number = %d", s, atoi(s));
    return 0;
}