/*
Write a program to concatenate two strings.
*/

#include <stdio.h>

int len(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringConcat(char s1[], char s2[]) {
    // concat s2 to s1
    int length = len(s1);
    for (int i = 0; s2[i] != '\0'; i++, length++) {
        s1[length] = s2[i];
    }
    s1[length] = '\0';
}

int main() {
    char str1[50] = "Hello ";
    char str2[50] = "world";

    stringConcat(str1, str2);
    printf("After concatenation: %s", str1);

    printf("\n\nProgrammed by Milan Bairagi");  // watermark

    return 0;
}