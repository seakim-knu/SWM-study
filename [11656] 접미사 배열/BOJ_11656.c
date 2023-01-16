/*
South Korea, 16 Jan, 2023
@seakim-knu
BOJ [11656] 접미사 배열
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000

int main() {
    char s[SIZE+1];
    char string[SIZE+1][SIZE+1];
    char temp[SIZE+1];
	int len;
    int i, j;

	scanf("%s", s);
	len = strlen(s);

	for (i = 0; i < len; i++){
		for (j = i; j < len; j++) {
			string[i][j-i] = s[j];
		}
	}

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1 - i; j++) {
			if (strcmp(string[j], string[j+1]) > 0) {
				strcpy(temp, string[j]);
				strcpy(string[j], string[j + 1]);
				strcpy(string[j + 1], temp);
			}
		}
	}

	for (i = 0; i < len; i++)
		printf("%s\n", string[i]);

	return 0;
}