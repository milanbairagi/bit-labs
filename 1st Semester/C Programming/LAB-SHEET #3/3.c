/*
Demonstrate the differences among getch(), getche(),
getchar(). Demonstrate the difference between scanf()
& gets() , printf() & puts().
*/

#include <stdio.h>

int main() {
    char c;
    char str[100];
    int num;

    printf("Enter a character using getch(): ");
    c = getch();
    printf("\nthe character entered using getch() is: %c\n", c);

    printf("Enter a character using getche(): ");
    c = getche();
    printf("\nThe character entered using getche() is: %c\n");

    printf("Enter a character using getchar(): ");
    c = getchar();
    printf("\nThe character entered using getchar() is %c\n", c);

    printf("Enter an integer using scanf(): ");
    scanf("%d", &num);
    printf("The integer entered using scanf() is: %d\n", num);

    printf("Enter a string using gets(): ");
    gets(str);
    printf("The string entered using gets() is: %s\n", str);

    printf("The text is printed using printf()");
    
    printf("\nEnter a string: ");
    scanf("%s", str);
    printf("The entered text printed using puts is ");
    puts(str);

    
    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}