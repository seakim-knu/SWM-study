/*
South Korea, 16 Jan, 2023
@seakim-knu
BOJ [10157] 자리배정
*/

#include <stdio.h>

int main() {
	int     c, r;
    int     num;
    int     x = 1, y = 0;
    int     direction   = 1;
    int     chk         = 0;
    int     i, j;
	
	scanf("%d %d", &c, &r);
	scanf("%d", &num);

	c--;

    if (num > (c + 1) * r)
        printf("0");	
    else{
        while (chk < num) {
            for (i = 0; i < r; i++) {
                y += direction;
                chk++;

                if(chk == num)
                    printf("%d %d\n", x, y);	   
            }

            for (i = 0; i < c; i++) {
                x += direction;
                chk++;
                if(chk == num)
                    printf("%d %d\n", x, y);
                
            }

            direction *= -1;				 
            c--;
            r--;					
        }
    }
	
    return 0;
}