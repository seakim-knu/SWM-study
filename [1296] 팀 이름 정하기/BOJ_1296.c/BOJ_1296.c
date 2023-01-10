/*
South Korea, 10 Jan, 2023
@seakim-knu
BOJ [1296] 팀 이름 정하기
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define LOVE(l, o, v, e) (((l+o)*(l+v)*(l+e)*(o+v)*(o+e)*(v+e))%100)

int main(){
    char    name[SIZE+1]        = "";
    char    candidate[SIZE+1]   = "";
    char    **team;
    int     *table1;
    int     **table2;
    int     n;
    int     max;
    int     i;
    int     j;
    int     k;
    
    scanf("%s", name);
    scanf("%d", &n);

    team = (char **)malloc(sizeof(char*) * n);

    for (i = 0; i < n; i++){
        team[i]=(char *)malloc(sizeof(char)*(SIZE+1));
    }

    if (team == NULL) {
        printf("Memory allocation error\n");
        exit(0);
    }

    for (i = 0; i < n; i++){
        scanf("%s", team[i]);
    }

    table1 = (int *)malloc(sizeof(int) * n);
    table2 = (int **)malloc(sizeof(int) * n);
    for(i=0; i<n; i++){
        table2[i]=(int *)malloc(sizeof(int)*4);
    }

    if (table1 == NULL) {
        printf("Memory allocation error\n");
        exit(0);
    }

    for (i = 0; i < SIZE; i++) {
        if (name[i] == 'L')
            table1[0]++;
        else if (name[i] == 'O')
            table1[1]++;
        else if (name[i] == 'V')
            table1[2]++;
        else if (name[i] == 'E')
            table1[3]++;
    }

    for(i=0; i<n; i++){
        for(j=0; j<SIZE; j++){
            if(team[i][j]=='L'){
                table2[i][j]++;
            }
            else if(team[i][j]=='O'){
                table2[i][j]++;
            }
            else if(team[i][j]=='V'){
                table2[i][j]++;
            }
            else if(team[i][j]=='E'){
                table2[i][j]++;
            }
        }
    }

    for(i=0; i<4; i++){
        printf("[%d] %d\n", i, table1[i]);
    }

   for(i=0; i<n; i++){
        for(j=0; j<4; j++){
        printf("[%d][%d] %d\n", i, j, table2[i][j]);
        }
   }
    // for(i=0; i<n; i++){
    //     for(j=0; j<4; j++){
    //         printf("%d ", table1[i][j]);
    //     }
    // }


    //     for (i = 0; i < ALPHABET; i++) {
    //     if (max == check[i])
    //         ans = '?';
    //     else if (max < check[i]) {
    //         max = check[i];
    //         ans = i + 'A';
    //     }
    // }


    // for (i = 0; i < 4; i++)
    //     printf("%d ", table1[i]);
    
    // printf("\n");
    // for(i=0; i<n; i++)
    // printf("%s ", team[i]);

    // printf("%c ", team[0][0]);

    return 0;
}