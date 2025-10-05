#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the target element
        }
    }
    return -1; // Return -1 if the target element is not found
}

void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = linearSearch(arr, size, target);
    printArray(arr, size);

    if (result != -1) {
        printf("Element (%d) found at index %d\n", target, result);
    } else {
        printf("Element (%d) not found in the array\n", target);
    }

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}