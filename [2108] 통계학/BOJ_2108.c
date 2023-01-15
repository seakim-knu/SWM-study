/*
South Korea, 16 Jan, 2023
@seakim-knu
BOJ [2108] 통계학
*/

#include <stdio.h>
#include <stdlib.h>

int static compare (const void* first, const void* second);

int main(){
    int     n;
    int     num;
    int     temp;
    int     *number;
    double  mean = 0;
    int     mid = 0, most = 0, range = 0;
    int     i, j;

    scanf("%d", &n);

    number = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        number[i] = num;
    }

    qsort(number, n, sizeof(int), compare);

    for (i = 0; i < n; i++)
        mean += (double)number[i];
    mean /= n;
    mean += 0.5;

    mid = number[((n + 1) / 2) - 1];
    
    /*

        최빈값 어떻게 ???????
        블로그 마다 있는 엄청 큰 배열도 이해가 잘 안된다 ;
        
        - 이해하기 싫다. 왜냐하면
            1) 그렇게나 큰 배열은 낭비같고
            2) 인덱스를 파악하는 시간을 효율적으로 못쓰는 거 같다

    */

    int max = number[n - 1];
    int min = number[0];
    range   = max - min;

    printf("%.0f\n%d\n%d\n%d\n", mean, mid, most, range);

    free(number);

    return 0;
}

int static compare (const void* first, const void* second) {
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}