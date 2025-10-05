// Write a C program to print truth table of AND, OR and NOT Operation

#include <stdio.h>

void printANDTable() {
    printf("AND Truth Table\n");
    printf("================\n");
    printf("A B | A AND B\n");
    printf("----+--------\n");
    for (int A = 0; A <= 1; A++) {
        for (int B = 0; B <= 1; B++) {
            printf("%d %d |   %d\n", A, B, A && B);
        }
    }
    printf("\n");
}

void printORTable() {
    printf("OR Truth Table\n");
    printf("===============\n");
    printf("A B | A OR B\n");
    printf("----+-------\n");
    for (int A = 0; A <= 1; A++) {
        for (int B = 0; B <= 1; B++) {
            printf("%d %d |  %d\n", A, B, A || B);
        }
    }
    printf("\n");
}

void printNOTTable() {
    printf("NOT Truth Table\n");
    printf("================\n");
    printf("A | NOT A\n");
    printf("--+------\n");
    for (int A = 0; A <= 1; A++) {
        printf("%d |   %d\n", A, !A);
    }
    printf("\n");
}

int main() {
    printANDTable();
    printORTable();
    printNOTTable();

    printf("\nPrgrammed by Milan Bairagi");  // Watermark
    return 0;
}