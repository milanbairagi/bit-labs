// Write a C program to implement union of set.
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

// Function to find the union of two sets
void unionOfSets(int set1[], int size1, int set2[], int size2, int unionSet[], int *unionSize) {
    int i, j;
    
    // Copy all elements of set1 to unionSet
    for (i = 0; i < size1; i++) {
        unionSet[i] = set1[i];
    }
    
    // Initialize the size of the union set
    *unionSize = size1;
    
    // Add elements of set2 to unionSet if they are not already present
    for (j = 0; j < size2; j++) {
        if (!isPresent(set1, size1, set2[j])) {
            unionSet[*unionSize] = set2[j];
            (*unionSize)++;
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
    
    // Maximum possible size of union set is size1 + size2
    int unionSet[size1 + size2];
    int unionSize;
    
    // Find the union of set1 and set2
    unionOfSets(set1, size1, set2, size2, unionSet, &unionSize);

    
    // Print the set1 and set2
    printf("Set 1 = ");
    printSet(set1, size1);
    printf("Set 2 = ");
    printSet(set2, size2);

    // Print the union set
    printf("Union of the two sets is: ");
    printSet(unionSet, unionSize);

    printf("\n\nProgrammed by Milan Bairagi...");
    
    return 0;
}