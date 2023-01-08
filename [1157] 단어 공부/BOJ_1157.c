/*
South Korea, 8 Jan, 2023
@seakim-knu
BOJ [1157] 단어 공부
*/

#include <stdio.h>
#include <string.h>

#define SIZE        1000000
#define ALPHABET    26

int main() {
    char    input[SIZE + 1] = "";
    int     capital         = 'a' - 'A';
    int     check[26]       = {0};
    int     max             = 0;
    char    ans;
    int     length;
    int     i;

    scanf("%s", input);
    length = strlen(input);

    for (i = 0; i < length; i++) {
        if (input[i] > 'Z') {
            input[i] -= capital;
        }
        check[input[i]-'A']++;
    }

    for (i = 0; i < ALPHABET; i++) {
        if (max == check[i])
            ans = '?';
        else if (max < check[i]) {
            max = check[i];
            ans = i + 'A';
        }
    }
    printf("%c\n", ans);

    return 0;
}