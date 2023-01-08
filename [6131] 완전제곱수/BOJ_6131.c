/*
South Korea, 9 Jan, 2023
@seakim-knu
BOJ [6131] 완전제곱수
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int     input;
    int     *box;
    int     count   = 0;
    int     ans     = 0;
    int     i;
    int     j = 0;

    scanf("%d", &input);

    for (i = 1; i <= input; i++)
        if (input % i == 0)
            count++;

    box = (int *)malloc(sizeof(int) * count);
    
    for (i = 1; i <= input; i++){
        if (input % i == 0){
            box[j]=i;
            j++;
        }
    }

    for (i = 0; i < count; i++)
        if (box[i] % 2 == 0 && box[count - i - 1] % 2 == 0 || box[i] % 2 == 1 && box[count - i - 1] % 2 == 1)
            ans++;

    printf("%d \n", ans/2);

    return 0;
}