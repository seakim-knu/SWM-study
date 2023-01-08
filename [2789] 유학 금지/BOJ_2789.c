/*
South Korea, 8 Jan, 2023
@seakim-knu
BOJ [2789] 유학 금지
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

void delete(char *, char);

int main() {
    char    check[10]       = "CAMBRIDGE";
    char    input[SIZE+1]   = "";
    char    *str;
    int     i;

    scanf("%s", input);

    str = (char *)malloc(strlen(input) + 1);
    if (str == NULL) {
        printf("Memory allocation error\n");
        exit(0);
    }

    strcpy(str, input);

    for (i = 0; i < strlen(check); i++)
        delete (str, check[i]);

    printf("%s\n", str);

    free(str);

    return 0;
}

void delete(char *str, char ch) {
    char *src, *dst;

    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;

        if (*dst != ch)
            dst++;
    }
    *dst = '\0';
}