/*
South Korea, 16 Jan, 2023
@seakim-knu
BOJ [1158] 요세푸스 문제
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int     n, k;
    int     num;
    int     *check;
    int     i, j;

    scanf("%d %d", &n, &k);

    check       = (int *)malloc(sizeof(int) * n);
    num         = k;
    check[num]  = 1;

    printf("<");
    printf("%d", num);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < k; j++) {
            while(1) {
                num++;
                if(num > n)
                    num = 1;
                if(!check[num])
                    break;
            }
        }
        printf(", ");
        printf("%d", num);
        check[num] = 1;
    }
    printf(">");

    return 0;
}