// Write a C program to implement intersection operation of set
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

// Function to find the intersection of two sets
void intersectionOfSets(int set1[], int size1, int set2[], int size2, int intersectionSet[], int *intersectionSize) {
    int i, j = 0;
    *intersectionSize = 0;
    for (i = 0; i < size1; i++) {
        if (isPresent(set2, size2, set1[i])) {
            intersectionSet[j++] = set1[i];
            (*intersectionSize)++;
        }
    }
}

// Function to display a set
void printSet(int set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d", set[i]);
        if (i != size - 1) printf(", ");
    }
    printf(" }\n");
}

int main() {
    int set1[] = {1, 2, 3, 4, 5};
    int set2[] = {4, 5, 6, 7, 8};
    int size1 = sizeof(set1) / sizeof(set1[0]);
    int size2 = sizeof(set2) / sizeof(set2[0]);
    
    // Maximum possible size of intersection set is size1 or size2
    int intersectionSet[size1];
    int intersectionSize;
    
    // Find the intersection of set1 and set2
    intersectionOfSets(set1, size1, set2, size2, intersectionSet, &intersectionSize);

    
    // Print the set1 and set2
    printf("Set 1 = ");
    printSet(set1, size1);
    printf("Set 2 = ");
    printSet(set2, size2);

    // Print the intersection set
    printf("intersection of the two sets is: ");
    printSet(intersectionSet, intersectionSize);

    printf("\n\nProgrammed by Milan Bairagi...");
    
    return 0;
}