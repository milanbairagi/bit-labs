/*
Write a program that uses pointers to iterate over an
array of integers and prints its values to the console.
*/

#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]); // Get array size

    int *ptr = numbers; // Initialize pointer to the first element

    // Loop through the array using the pointer
    for (int i = 0; i < size; i++) {
        printf("%d ", *ptr); // Print the value pointed to by ptr
        ptr++; // Increment the pointer to point to the next element
    }

    printf("\n\nProgrammed by Milan Bairagi"); // Print a newline character
    return 0;
}
