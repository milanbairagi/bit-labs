// Write a C program to implement difference operation of set. 

#include <stdio.h>

// Function to check if an element is present in the array
int isPresent(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1;
        }
    }
    return 0;
}

void printSet(int set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d", set[i]);
        if (i != size - 1) printf(", ");
    }
    printf(" }\n");
}

// Function to find the difference of two sets
void setDifference(int setA[], int sizeA, int setB[], int sizeB, int result[], int *resultSize) {
    int i, j = 0;
    *resultSize = 0;

    for (i = 0; i < sizeA; i++) {
        if (!isPresent(setB, sizeB, setA[i])) {
            result[j++] = setA[i];
            (*resultSize)++;
        }
    }
}


int main() {
    int setA[] = {1, 2, 3, 4, 5};
    int setB[] = {3, 4, 6, 7};
    int sizeA = sizeof(setA) / sizeof(setA[0]);
    int sizeB = sizeof(setB) / sizeof(setB[0]);
    
    int difference[sizeA]; 
    int differenceSize;

    setDifference(setA, sizeA, setB, sizeB, difference, &differenceSize);

    
    // Print the set1 and set2
    printf("Set A: ");
    printSet(setA, sizeA);
    printf("Set B: ");
    printSet(setB, sizeB);

    printf("Difference of setA and setB (setA - setB): ");
    printSet(difference, differenceSize);
    printf("\n\nProgrammed by Milan Bairagi.");

    return 0;
}