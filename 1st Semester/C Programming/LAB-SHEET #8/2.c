/*
Write a program to copy one string to another string with and without suing string 
handling function.
*/

#include <stdio.h>
#include <string.h>

void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Add null terminator to the destination string
}

int main() {
    char str1[50] = "Hello, world!";
    char str2[50];
    char str3[50];

    printf("Using string handling function:\n");
    strcpy(str2, str1);
    printf("Original string: %s\n", str1);
    printf("Copied string:   %s\n", str2);

    printf("\nWithout using string handling function:\n");
    copyString(str3, str1);
    printf("Original string: %s\n", str1);
    printf("Copied string:   %s\n", str3);

    printf("\n\nProgrammed by Milan Bairagi");  // watermark

    return 0;
}
