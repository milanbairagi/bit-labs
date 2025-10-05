/*
Write set of strings each of length 40 into a file
“string.txt” and display it (use fputs() and fgets()
function).
*/

#include <stdio.h>

int main() {
    FILE *fp = fopen("string.txt", "w"); // Open file in write mode

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write three strings of length 40 to the file
    fputs("Jumping foxes zigzag through the woods\n", fp);
    fputs("Quick brown fox jump over the lazy dog\n", fp);
    fputs("Quick brown dogs chase fluffy squirrel\n", fp);

    fclose(fp); // Close the file

    printf("Strings written to string.txt\n");

    // Open the file in read mode
    fp = fopen("string.txt", "r");

    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    char buffer[41]; // Buffer to hold each string

    printf("\nContents of string.txt:\n");

    // Read and display each string using fgets
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}
