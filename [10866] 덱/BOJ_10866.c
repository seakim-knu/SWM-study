/*
South Korea, 16 Jan, 2023
@seakim-knu
BOJ [10866] 덱
*/

#include<stdio.h>
#include<string.h>

#define SIZE 10000
int     deque[SIZE+1] = {0};
char    operand[15];
int     cnt = 0;

void    push_front(int);
void    push_back(int);
void    pop_front();
void    pop_back();

int main() {
	int n;
    int number;
    int i;

	scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", operand);

	    if(strcmp(operand, "push_front") == 0){
	        scanf("%d", &number);
	        push_front(number);
	    }
	    if(strcmp(operand, "push_back") == 0){
	        scanf("%d", &number);
	        push_back(number);
	    }
	    else if(strcmp(operand, "pop_front") == 0){
	        pop_front();
	    }
	    else if(strcmp(operand, "pop_back") == 0){
	        pop_back();
	    }
	    else if(strcmp(operand, "size") == 0){
            printf("%d\n", cnt);
	    }
	    else if(strcmp(operand, "empty") == 0){
            if (cnt == 0 && deque[cnt] == 0)
                printf("1\n");
             else
                printf("0\n");
	    }
	    else if(strcmp(operand, "front") == 0){
            if (cnt == 0 && deque[cnt] == 0)
                printf("-1\n");
            else
                printf("%d\n", deque[0]);
	    }
	    else if(strcmp(operand, "back") == 0){
	        if (cnt == 0 && deque[cnt] == 0)
                printf("-1\n");
            else
                printf("%d\n", deque[cnt-1]);
	    }
    }

    return 0;
}

void push_front(int number) {
    int     i;

    for (i = cnt; i >= 0; i--)
        deque[i+1] = deque[i];

    deque[0] = number;
    cnt++;
}

void push_back(int number) {
    deque[cnt] = number;
    cnt++;
}
void pop_front(){
    int     i;

    if(deque[0] == 0 && cnt == 0)
        printf("-1\n");
    else{
        printf("%d\n", deque[0]);

        for (i = 0; i < cnt; i++){
            deque[i] = deque[i+1];
        }
        deque[cnt] = 0;
        cnt--;
    }
}
void pop_back(){
    if(deque[0] == 0 && cnt == 0)
        printf("-1\n");
    else{
        printf("%d\n", deque[cnt-1]);
        deque[cnt-1] = 0;
        cnt--;
    }
}