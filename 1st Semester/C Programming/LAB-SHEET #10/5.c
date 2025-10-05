/*
Write a program that copies the contents of one file to
another. Use the fopen() function to open the source
file and the destination file,and the use a loop to read
and write each character in the source file.
*/

#include <stdio.h>

int main() {
    char sourceFile[100], destinationFile[100];
    int ch;

    // Get source and destination file names
    printf("Enter source file name: ");
    scanf("%s", sourceFile);

    printf("Enter destination file name: ");
    scanf("%s", destinationFile);

    // Open source file in read mode
    FILE *source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error opening source file!\n");
        return 1;
    }

    // Open destination file in write mode
    FILE *destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        printf("Error opening destination file!\n");
        fclose(source); // Close source if destination fails
        return 1;
    }

    // Copy characters until EOF (End Of File) is reached
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    // Close both files
    fclose(source);
    fclose(destination);

    printf("File copied successfully!\n");

    printf("\nProgrammed by Milan Bairagi");

    return 0;
}
