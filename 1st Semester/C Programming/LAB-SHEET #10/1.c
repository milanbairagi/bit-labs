/*
Write characters into a file ‘file.txt’. The set of
characters are read from the keyboard until an enter
key is pressed (use putc() and getc() function).
*/

#include <stdio.h>

int main() {
    FILE *fp = fopen("file.txt", "w"); // Open file in write mode

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char ch;

    printf("Enter characters (press Enter to finish):\n");
    while ((ch = getchar()) != '\n') {
        putc(ch, fp); // Write character to file
    }

    fclose(fp); // Close the file
    printf("Characters written to file.txt\n");

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}
