/*
South Korea, 10 Jan, 2023
@seakim-knu
BOJ [6996] 애너그램
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

int main(){
    int n;
    char **a;
    char **b;
    int i;
    int j;

    scanf("%d", &n);

    a=(char **)malloc(sizeof(char*)*n);
    b=(char **)malloc(sizeof(char*)*n);

    for (i = 0; i < n; i++) {
        a[i]=(char *)malloc(sizeof(char)*(SIZE+1));
        b[i]=(char *)malloc(sizeof(char)*(SIZE+1));
    }

    for (i = 0; i < n; i++) {
        scanf("%s %s", a[i], b[i]);
    }

    for(i=0; i<n; i++){
        if(strlen(a[i])!=strlen(b[i]))
            printf("%s & %s are NOT anagrams.\n", a[i], b[i]);
        else{
            printf("%s & %s are anagrams.\n", a[i], b[i]);
        }
    }

    // for (i = 0; i < n; i++) {
    //     printf("%s %s\n", a[i], b[i]);
    // }

    return 0;
}