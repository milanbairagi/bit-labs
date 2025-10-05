// Program to test properties of relation.

#include <stdio.h>
#include <stdbool.h>

// Function to check reflexivity
bool isReflexive(int set[], int size, int relation[][2], int relSize) {
    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < relSize; j++) {
            if (set[i] == relation[j][0] && set[i] == relation[j][1]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

// Function to check symmetry
bool isSymmetric(int relation[][2], int relSize) {
    for (int i = 0; i < relSize; i++) {
        bool found = false;
        for (int j = 0; j < relSize; j++) {
            if (relation[i][0] == relation[j][1] && relation[i][1] == relation[j][0]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

// Function to check transitivity
bool isTransitive(int relation[][2], int relSize) {
    for (int i = 0; i < relSize; i++) {
        for (int j = 0; j < relSize; j++) {
            if (relation[i][1] == relation[j][0]) {
                bool found = false;
                for (int k = 0; k < relSize; k++) {
                    if (relation[k][0] == relation[i][0] && relation[k][1] == relation[j][1]) {
                        found = true;
                        break;
                    }
                }
                if (!found) return false;
            }
        }
    }
    return true;
}

int main() {
    int set[] = {1, 2, 3};
    int relation[][2] = {{1, 1}, {2, 2}, {3, 3}, {1, 2}, {2, 1}, {2, 3}, {3, 2}};
    int size = sizeof(set) / sizeof(set[0]);
    int relSize = sizeof(relation) / sizeof(relation[0]);

    printf("Set: { ");
    for (int i = 0; i < size; i++) {
        printf("%d", set[i]);
        if (i != size - 1) printf(", ");
    }
    printf(" }\n");

    printf("Relation: { ");
    for (int i = 0; i < relSize; i++) {
        printf("(%d, %d)", relation[i][0], relation[i][1]);
        if (i != relSize - 1) printf(", ");
    }
    printf(" }\n");

    printf("Reflexive: %s\n", isReflexive(set, size, relation, relSize) ? "Yes" : "No");
    printf("Symmetric: %s\n", isSymmetric(relation, relSize) ? "Yes" : "No");
    printf("Transitive: %s\n", isTransitive(relation, relSize) ? "Yes" : "No");

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}
