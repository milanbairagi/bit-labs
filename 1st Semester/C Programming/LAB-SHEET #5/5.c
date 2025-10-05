/*
Write a program to display the following pattern.
a)
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
b)
*
* *
* * *
* * * *
* * * * *
c)
1 6 10 13 15
2 7 11 14
3 8 12
4 9
5
*/

#include <stdio.h>

void pattern1(int row);
void pattern2(int row);
void pattern3(int row);

int main() {
    int row = 5;

    pattern1(row);
    pattern2(row);
    pattern3(row);

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}

void pattern1(int row) {
    printf("Pattern (a): \n");
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void pattern2(int row) {
    printf("\nPattern (b): \n");
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void pattern3(int row) {
    printf("\nPattern (c): \n");
    for (int i = 1; i <= row; i++) {
        int num = i;
        int d = row;
        for (int j = 1; j <= row-i+1; j++) {
            printf("%d ", num);
            num += d;
            d--;
        }
        printf("\n");
    }
}
