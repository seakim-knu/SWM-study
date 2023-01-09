/*
South Korea, 9 Jan, 2023
@seakim-knu
BOJ [2798] 블랙잭
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int     n;
    int     m;
    int     *card;
    int     num;
    int     sum     = 0;
    int     count   = 0;
    int     i;
    int     j;
    int     k;

    scanf("%d %d", &n, &m);

    card = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        card[i] = num;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            for (k = j + 1; k < n; k++) {
                sum = card[i] + card[j] + card[k];
                if (sum > count && sum <= m)
                    count = sum;
            }
        }
    }

    printf("%d\n", count);

    free(card);
    return 0;
}