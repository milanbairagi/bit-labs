/*
1. Write a program to find the largest and smallest among the three entered numbers and
also display whether the identified largest /smallest number is even or odd.
*/

#include <stdio.h>

char * oddOrEven(int num) {
    if (num % 2 == 0) {
        return "even";
    }
    return "odd";
} 


int main() {
    int nums[3];
    int largest, smallest;
    printf("Enter 3 numbers: ");

    scanf("%d%d%d", &nums[0], &nums[1], &nums[2]);

    // find largest number
    largest = nums[0];
    for (int i = 1; i < 3; i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }
    
    // find smallest number
    smallest = nums[0];
    for (int i = 1; i < 3; i++) {
        if (nums[i] < smallest) {
            smallest = nums[i];
        }
    }

    printf("\nLargest Number: %d\n", largest);
    printf("Smallest Number: %d\n", smallest);

    printf("\nThe largest number (%d) is %s.\n", largest, oddOrEven(largest));
    printf("The smallest number (%d) is %s.\n", smallest, oddOrEven(smallest));

    printf("\nProgrammed by Milan Bairagi");

    return 0;
}