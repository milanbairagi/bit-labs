/*
Write a program to read a string and check for
palindrome without using string related function.
*/

#include <stdio.h>

int len(char string[]) {
    /*Return lenght of the string*/
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}


int isPalindrome(char string[]) {
    int length = len(string);
    for (int i = 0; i < length / 2; i++) {
        if (string[i] != string[length - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char string[20];

    printf("Enter a string: ");
    scanf("%s", string);

    if (isPalindrome(string)) {
        printf("The string \"%s\" is palindrome.", string);
    } else {
        printf("The string \"%s\" is not palindrome.", string);
    }

    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}