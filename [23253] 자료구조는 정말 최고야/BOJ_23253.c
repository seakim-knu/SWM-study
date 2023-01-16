/*
South Korea, 16 Jan, 2023
@seakim-knu
BOJ [23253] 자료구조는 정말 최고야
*/

#include <stdio.h>
#include<stdlib.h>

int main(){
    int     n, m;
    int     *book;
    int     dummy;
    int     chk = 0;
    int     i, j, k;

    scanf("%d %d",&n,&m);

    for (i = 0; i < m; i++) {
        scanf("%d",&dummy);
        book = (int *)malloc(sizeof(int) * dummy);

        for (j = 0; j < dummy; j++)
            scanf("%d", &book[j]);

        for (k = 0; k < dummy - 1; k++) {
            if (book[k] < book[k + 1]) {
                chk = 1;
                break;
            }
            if (chk == 1)
                break;
        }
        if (i == m - 1 && chk != 1)
            printf("Yes");
    }

    if (chk == 1)
        printf("No");

    return 0;
}