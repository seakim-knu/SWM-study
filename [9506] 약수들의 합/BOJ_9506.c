/*
South Korea, 10 Jan, 2023
@seakim-knu
BOJ [9506] 약수들의 합
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int chk;
    int i;

    while (1) {
        chk = 0;
        scanf("%d", &n);

        if (n == -1)
            break;

        for (i = 1; i < n; i++)
            if (n % i == 0)
                chk += i;

        if (chk == n) {
            printf("%d = 1", n);
            for (i = 2; i < n; i++)
                if (n % i == 0)
                    printf(" + %d", i);
            printf("\n");
        }
        else
            printf("%d is NOT perfect.\n", n);
    }

    return 0;
}