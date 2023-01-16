/*
South Korea, 16 Jan, 2023
@seakim-knu
BOJ [4949] 균형잡힌 세상
*/

#include <stdio.h>
#include <string.h>

#define SIZE 100
 
char    stack[SIZE];
int     top = -1;

int     push(char);
int     pop();
char    peek();
void    check(char *, int);
 
int main() {
    char string[SIZE];

    while (1) {
        top = -1;
        scanf("%s", string);

        if (strcmp(string, ".") == 0) 
            break;

        check(string, strlen(string));
    }
    return 0;
}

int push(char string) {
    if (top >= SIZE - 1) return -1;
    return stack[++top] = string;
}
 
int pop() {
    if (top < 0) return -1;
    return stack[top--] = '\0';
}
 
char peek() {
    return stack[top];
}
 
void check(char *string, int size) {
    int     i;

    for (i = 0; i < size; i++) {
        if (string[i] == '(' || string[i] == ')' || string[i] == '[' || string[i] == ']') {
            if (top == -1) 
                push(string[i]);
            else {
                if (peek() == '('&&string[i] == ')')
                    pop();
                else if (peek() == '['&&string[i] == ']') 
                    pop();
                else 
                    push(string[i]);
            }
        }
    }
    if (top == -1)
        printf("yes\n");
    else
        printf("no\n");
}