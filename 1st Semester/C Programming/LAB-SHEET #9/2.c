/*
Write a program which accepts structure as argument
and returns structure to the calling program.
*/

#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int roll;
};

struct student funct(struct student studs) {
    // strcpy(studs.name,"Alex");
    char newName[50] = "Mr. ";
    strcat(newName, studs.name);  // newName = Mr. <name>
    strcpy(studs.name, newName);  // name = newName
    
    return studs;
} 

int main() {
    struct student stud;
    printf("\nEnter the name: ");
    gets(stud.name);
    printf("\nEnter the roll: ");
    scanf("%d",&stud.roll);

    struct student stud1=funct(stud);
    printf("\nThe values of the returned structure is:");
    printf("\nName: %s\nRoll: %d",stud1.name,stud1.roll);

    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}