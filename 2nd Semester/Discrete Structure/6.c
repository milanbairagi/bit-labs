// Write a C program to implement Cartesian product.
#include <stdio.h>

// Function to print the Cartesian product of two sets
void cartesianProduct(int setA[], int sizeA, int setB[], int sizeB) {
    printf("{ ");
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            printf("(%d, %d)", setA[i], setB[j]);
            if (i != sizeA - 1 || j != sizeB - 1) {
                printf(", ");
            }
        }
    }
    printf(" }\n");
}

void printSet(int set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d", set[i]);
        if (i != size - 1) printf(", ");
    }
    printf(" }\n");
}


int main() {
    int setA[] = {1, 2, 3};
    int setB[] = {4, 5};

    int sizeA = sizeof(setA) / sizeof(setA[0]);
    int sizeB = sizeof(setB) / sizeof(setB[0]);

    printf("Set A: ");
    printSet(setA, sizeA);
    
    printf("Set B: ");
    printSet(setB, sizeB);

    printf("Cartesian Product of A and B: ");
    cartesianProduct(setA, sizeA, setB, sizeB);

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}