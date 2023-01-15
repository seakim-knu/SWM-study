/*
South Korea, 16 Jan, 2023
@seakim-knu
BOJ [1316] 그룹 단어 체커
*/

#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(){
    int     num;
    int     len;
    int     cnt = 0;
    int     i;
    int     j;

    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        char word[SIZE + 1];
        scanf("%s", word);

        len = strlen(word);
        int alphabet[26] = {0};
        for (j = 0; j < len; j++) {
            char chk = word[j];

            if (alphabet[chk - 'a'] == 0)
                alphabet[chk - 'a'] = 1;
            else
                if (word[j - 1] != word[j])
                    break;
            if (j == len - 1)
                cnt++;
        }
    }

    printf("cnt: %d \n", cnt);
            
    return 0;
}