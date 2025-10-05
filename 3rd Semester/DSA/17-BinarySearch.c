#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;

    while (end >= start) {
        int mid = (start + end) / 2;

        if (arr[mid] == target) 
            return mid;
        if (target < mid)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    printArray(arr, size);

    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Element (%d) is present at index %d.\n", target, result);
    else
        printf("Element (%d) is not present in array.\n", target);

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}