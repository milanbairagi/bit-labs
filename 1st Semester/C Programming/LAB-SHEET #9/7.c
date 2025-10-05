/*
Write a program that uses pointer to structure. Create
a structure to store information about book including
its title, author, and publication- year. Use a pointer
to the structure to access the members of the structure
to display in console.
*/

#include <stdio.h>

struct Book {
    char title[50];
    char author[50];
    int year;
};

void displayBook(struct Book *ptr) {
    printf("Title: %s\n", ptr->title);
    printf("Author: %s\n", ptr->author);
    printf("Year: %d\n", ptr->year);
}

int main() {
    struct Book book = {"The Lord of the Rings", "J.R.R. Tolkien", 1954};
    struct Book *ptrBook = &book;

    displayBook(ptrBook);

    printf("\nProgrammed by Milan Bairagi");

    return 0;
}
