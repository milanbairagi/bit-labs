/*
Read characters from file “file.txt” created in
question 1. Also count the number of character in the
file (use fputs() and fgets() function)
*/

#include <stdio.h>

int main() {
    FILE *fp = fopen("file.txt", "r"); // Open file in read mode

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int characterCount = 0;
    char ch;

    printf("Reading characters from file.txt...\n");

    // Read characters until EOF (End Of File) is reached
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
        characterCount++;
    }

    fclose(fp); // Close the file

    printf("\nTotal characters: %d\n", characterCount);

    printf("\nProgrammed by Milan Bairagi");

    return 0;
}
