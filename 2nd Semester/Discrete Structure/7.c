// Program to represent relations

#include <stdio.h>

// Function to print the relation
void printRelation(int setA[], int sizeA, int setB[], int sizeB) {
    printf("{ ");
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (setA[i] == setB[j]) {
                printf("(%d, %d) ", setA[i], setB[j]);
            }
        }
    }
    printf("}\n");
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
    int setB[] = {0, 1, 2, 4};

    int sizeA = sizeof(setA) / sizeof(setA[0]);
    int sizeB = sizeof(setB) / sizeof(setB[0]);

    printf("Set A: ");
    printSet(setA, sizeA);
    
    printf("Set B: ");
    printSet(setB, sizeB);

    printf("Relation between Set A and Set B: \n");
    printf("R = {(a,b) | a=b} Then \nR = ");
    printRelation(setA, sizeA, setB, sizeB);

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}
