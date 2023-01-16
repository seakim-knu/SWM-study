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
 
int     push(char ch);
int     pop();
char    read();
 
int main() {
    char    string[SIZE];
    int     len;
    int     i;

    while(1) {
        top = -1;
        gets(string);
        if (strcmp(string, ".") == 0)
            break;

        len = strlen(string);

        for (i = 0; i < len; i++) {
        if (string[i] == '(' || string[i] == ')' || string[i] == '[' || string[i] == ']') {
            if (top == -1) 
                push(string[i]);
            else {
                if (read() == '('&&string[i] == ')') pop();
                else if (read() == '['&&string[i] == ']') pop();
                else push(string[i]);
            }
        }
    }

    if (top == -1)
        printf("yes\n");
    else 
        printf("no\n");
    }

    return 0;
}

int push(char ch) {
    if (top >= SIZE - 1) 
        return -1;
    return stack[++top] = ch;
}
 
int pop() {
    if (top < 0) 
        return -1;
    return stack[top--] = '\0';
}
 
char read() {
    return stack[top];
}