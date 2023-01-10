/*
South Korea, 10 Jan, 2023
@seakim-knu
BOJ [10798] 세로읽기
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

int main(){
    int     n = 5;
    char    **word;
    int     i;
    int     j;

    word = (char **)malloc(sizeof(char *) * n);
    for (i = 0; i < n; i++) {
        word[i] = (char *)malloc(sizeof(char) * (SIZE + 1));
    }

    for (i = 0; i < n; i++) {
        scanf("%s", word[i]);
    }

    for (j = 0; j < SIZE; j++) {
        for (i = 0; i < n; i++) {
            printf("%c", word[i][j]);
        }
    }

    return 0;
}