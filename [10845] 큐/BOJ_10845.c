/*
South Korea, 16 Jan, 2023
@seakim-knu
BOJ [10845] 큐
*/
 
#include<stdio.h>
#include<string.h>

#define SIZE 10000

int     queue[SIZE+1] = {0};
char    operand[15];
int     cnt = 0;

void    push(int);
void    pop();

int main() {
	int n;
    int number;
    int i;

	scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", operand);

	    if(strcmp(operand, "push") == 0){
	        scanf("%d", &number);
	        push(number);
	    }
	    else if(strcmp(operand, "pop") == 0){
	        pop();
	    }
	    else if(strcmp(operand, "size") == 0){
            printf("%d\n", cnt);
	    }
	    else if(strcmp(operand, "empty") == 0){
            if (cnt == 0 && queue[cnt] == 0)
                printf("1\n");
             else
                printf("0\n");
	    }
	    else if(strcmp(operand, "front") == 0){
            if (cnt == 0 && queue[cnt] == 0)
                printf("-1\n");
            else
                printf("%d\n", queue[0]);
	    }
	    else if(strcmp(operand, "back") == 0){
	        if (cnt == 0 && queue[cnt] == 0)
                printf("-1\n");
            else
                printf("%d\n", queue[cnt-1]);
	    }
    }

    return 0;
}

void push(int number) {
    queue[cnt] = number;
    cnt++;
}
void pop(){
    int     i;

    if(queue[0] == 0 && cnt == 0)
        printf("-1\n");
    else{
        printf("%d\n", queue[0]);

        for (i = 0; i < cnt; i++){
            queue[i] = queue[i+1];
        }
        queue[cnt] = 0;
        cnt--;
    }
}