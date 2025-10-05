/*
Create a structure named company which has name,
address, phone, no Of Employee as member
variables. Read name of company, its address, phone
and noOfEmployee. Finally display the members’
value.
*/

#include <stdio.h>

struct company {
    char name[40];
    char address[40];
    int phone;
    int noOfEmployee;
} cmp;

int main() {
    printf("Enter the name of company: ");
    gets(cmp.name);
    printf("Enter the address of company: ");
    gets(cmp.address);
    printf("Enter the phone of company: ");
    scanf("%d",&cmp.phone);
    printf("Enter the no of employees of company: ");
    scanf("%d",&cmp.noOfEmployee);

    printf("\nCompany Details:");
    printf("\nName: %s",cmp.name);
    printf("\nAddress: %s",cmp.address);
    printf("\nPhone: %d",cmp.phone);
    printf("\nNo of Employees: %d",cmp.noOfEmployee);


    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}