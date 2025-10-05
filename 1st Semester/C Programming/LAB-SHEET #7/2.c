/*
Write a program that asks the user to enter 5 integers and store them in an array. 
Print the elements of the array in the console.
*/

#include <stdio.h>

int main() {
    int nums[5];
    
    printf("Enter the 5 numbers:\n");
    // input numbers from user to assign to nums array
    for (int i = 0; i < 5; i++) {
        printf("Number: ");
        scanf("%d", &nums[i]);
    }

    // print elements of array nums
    printf("\nElements of the array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}