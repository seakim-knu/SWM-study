/*
South Korea, 16 Jan, 2023
@seakim-knu
BOJ [1764] 듣보잡
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

int main(){
    int     n, m;
    char    **hear;
    char    **see;
    char    temp[SIZE+1];
    int     chk = 0;
    int     i, j;

    scanf("%d %d", &n, &m);

    hear = (char **)malloc(sizeof(char *) * n);
    for (i = 0; i < n; i++) {
        hear[i] = (char *)malloc(sizeof(char) * (SIZE + 1));
        scanf("%s", hear[i]);
    }

    see = (char **)malloc(sizeof(char *) * m);
    for (i = 0; i < m; i++) {
        see[i] = (char *)malloc(sizeof(char) * (SIZE + 1));
        scanf("%s", see[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(hear[i], hear[j]) > 0) {
                strcpy(temp, hear[i]);
                strcpy(hear[i], hear[j]);
                strcpy(hear[j], temp);
            }
        }
    }

    for (i = 0; i < m - 1; i++) {
        for (j = i + 1; j < m; j++) {
            if (strcmp(see[i], see[j]) > 0) {
                strcpy(temp, see[i]);
                strcpy(see[i], see[j]);
                strcpy(see[j], temp);
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((strcmp(hear[i], see[j])) == 0)
                chk++;
        }
    }

    printf("%d\n", chk);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((strcmp(hear[i], see[j])) == 0)
                printf("%s\n", hear[i]);
        }
    }

    free(hear);
    free(see);

    return 0;
}