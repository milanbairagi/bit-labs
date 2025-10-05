/*
Write a program to print the following pattern.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char string[]="UNIVERSITY";
    for (int i = 2; i <= strlen(string); i = i + 2) {
        for (int j = 0; j < i; j++) {
            printf("%c ",string[j]);
        }
        printf("\n");
    }
    for (int i = strlen(string) - 2; i >= 0; i = i - 2) {
        for (int j=0;j<i;j++) {
            printf("%c ",string[j]);
        }
        printf("\n");
    }
    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}