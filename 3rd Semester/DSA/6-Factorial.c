#include <stdio.h>

// Function to calculate factorial recursively
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Factorial of %d is %d\n", number, factorial(number));

    printf("\nProgrammed by Milan Bairagi...");
    return 0;
}
