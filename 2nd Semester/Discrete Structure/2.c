// program to print truth table for tautology and contradiction operations

#include <stdio.h>

int printTautologyTT() {
    printf("Tautology\n");
    printf("==========\n");
    printf("A  (NOT A) | A v (NOT A)\n");
    printf("-----------+------------\n");
    for (int A = 0; A <= 1; A++) {
        int tautology = A || (!A);
        printf("%d   %d      |     %d\n", A, !A, tautology);
    }
    printf("\n");
}


int printContradictionTT() {
    printf("Contradiction\n");
    printf("==============\n");
    printf("A  (NOT A) | A ^ (NOT A)\n");
    printf("-----------+------------\n");
    for (int A = 0; A <= 1; A++) {
        int contradiction = A && (!A);
        printf("%d   %d      |     %d\n", A, !A, contradiction);
    }
    printf("\n");
}

int main() {
    printTautologyTT();
    printContradictionTT();

    printf("\nProrammed by Milan Bairagi");  // Watermark

    return 0;
}