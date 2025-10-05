/*
Write a program that defines a function that takes an
array of integers as a parameter. The function should
print the sum of the elements in the array to the
console. Call the function with an array of your
choice.
*/

#include <stdio.h>

int sumOfArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {1, 6, 2, 9};

    printf("Sum of the elements: %d", sumOfArray(arr, 4));

    printf("\n\nProgrammed by Milan Bairagi");
    
    return 0;
}