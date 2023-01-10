/*
South Korea, 10 Jan, 2023
@seakim-knu
BOJ [11568] 민균이의 계략
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int     n;
    int     num;
    int     *card;
    int     *count;
    int     ans;
    int     i;
    int     j;

    scanf("%d", &n);

    card  = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        card[i] = num;
    }

    count = (int *)malloc(sizeof(int) * n);

    count[0] = 1;
    ans      = count[0];

    for (i = 0; i < n; i++) {
        count[i] = 1;
        for (j = 0; j < i; j++) {
            if (card[i] > card[j] && count[j] + 1 > count[i])
                count[i] = count[j] + 1;
        }
        if (ans < count[i])
            ans = count[i];
    }

    printf("%d\n", ans);

    return 0;
}