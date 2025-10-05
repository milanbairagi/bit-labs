/*
3. Write a program to calculate simple and compound interest.
*/

#include <stdio.h>
#include <math.h>

float calSI(float p, float r, int t) {
    return p * t * r / 100.0;
}

float calCI(float p, float r, int t) {
    return p * (pow((1 + r / 100.0), t) - 1);
}

int main() {
    float principal, rate;
    int time;

    printf("Enter principal amount: ");
    scanf("%f", &principal);

    printf("Enter rate of interest: ");
    scanf("%f", &rate);

    printf("Enter time (in years): ");
    scanf("%d", &time);

    float sI = calSI(principal, rate, time);
    printf("Simple Interest: %.2f\n", sI);

    float cI = calCI(principal, rate, time);
    printf("Compound Interest: %.2f\n", cI);

    printf("\nProgrammed by Milan Bairagi");  // watermark

    return 0;
}