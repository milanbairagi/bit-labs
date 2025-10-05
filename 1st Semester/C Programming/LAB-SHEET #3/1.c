/*
Write a program to produce the output as shown.
X       y    expression  results
3   | 3     | x=y+3     | x=6
3   | 3     | x=y-2     | x=1
3   | 3     | x=y*5     | x=15
3   | 3     | x=x/y     | x=2
3   | 3     | x=x%y     | x=0
*/

#include <stdio.h>

int main() {
    int x = 3, y = 3;

    printf("X     Y    expression  result\n");
    printf("%d  |  %d  |   x=y+3   | x=%d\n", x, y, y+3);
    printf("%d  |  %d  |   x=y-2   | x=%d\n", x, y, y-2);
    printf("%d  |  %d  |   x=y*5   | x=%d\n", x, y, y*5);
    printf("%d  |  %d  |   x=x/y   | x=%d\n", x, y, x/y);
    printf("%d  |  %d  |   x=x%%y   | x=%d\n", x, y, x%y);

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}