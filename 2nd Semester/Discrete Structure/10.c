// Write a C Program to demonstrate the operation of fuzzy set operations.
#include <stdio.h>

// Function to find the union of two fuzzy sets
void fuzzyUnion(float setA[], float setB[], float result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = (setA[i] > setB[i]) ? setA[i] : setB[i];
    }
}

// Function to find the intersection of two fuzzy sets
void fuzzyIntersection(float setA[], float setB[], float result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = (setA[i] < setB[i]) ? setA[i] : setB[i];
    }
}

// Function to find the complement of a fuzzy set
void fuzzyComplement(float set[], float result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = 1.0 - set[i];
    }
}

// Function to print a fuzzy set
void printFuzzySet(float set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%.2f", set[i]);
        if (i != size - 1) printf(", ");
    }
    printf(" }\n");
}

int main() {
    float setA[] = {0.1, 0.5, 0.8, 0.3};
    float setB[] = {0.7, 0.4, 0.6, 0.2};
    int size = sizeof(setA) / sizeof(setA[0]);

    float unionResult[size];
    float intersectionResult[size];
    float complementResultA[size];
    float complementResultB[size];

    fuzzyUnion(setA, setB, unionResult, size);
    fuzzyIntersection(setA, setB, intersectionResult, size);
    fuzzyComplement(setA, complementResultA, size);
    fuzzyComplement(setB, complementResultB, size);

    printf("Set A: ");
    printFuzzySet(setA, size);
    printf("Set B: ");
    printFuzzySet(setB, size);

    printf("Union of A and B: ");
    printFuzzySet(unionResult, size);

    printf("Intersection of A and B: ");
    printFuzzySet(intersectionResult, size);

    printf("Complement of A: ");
    printFuzzySet(complementResultA, size);

    printf("Complement of B: ");
    printFuzzySet(complementResultB, size);

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}
