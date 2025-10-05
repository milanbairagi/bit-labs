/*
Write a program to read RollNo, Name, Address,
Age & average-marks of 12 students in the BCT calls
and display the details from functions.
*/

#include <stdio.h>

struct student
{
    char name[20];
    int rollNo;
    char address[20];
    int age;
    int avgMark;
};

void displayStudentDetails(struct student stds[], int n) {
    printf("+-----------------+----------+----------------------+-----+--------------+\n");
    printf("| Name            | Roll No. | Address              | Age | Average Mark |\n");
    printf("+-----------------+----------+----------------------+-----+--------------+\n");

    for (int i = 0; i < n; i++) {
        printf("| %-15s | %-8d | %-20s | %-3d | %-12d |\n",
            stds[i].name, stds[i].rollNo, stds[i].address, stds[i].age, stds[i].avgMark);
    }

    printf("+-----------------+----------+----------------------+-----+--------------+\n");
}


int main() {
    struct student studentDetail[12];
    for (int i = 0; i < 12; i++) {
        printf("Student no. %d:\n", i+1);

        fflush(stdin);
        printf("\tName: ");
        gets(studentDetail[i].name);

        printf("\tRoll No.: ");
        scanf("%d", &studentDetail[i].rollNo);

        fflush(stdin);
        printf("\tAddress: ");
        gets(studentDetail[i].address);

        printf("\tAge: ");
        scanf("%d", &studentDetail[i].age);

        printf("\tAverage Mark: ");
        scanf("%d", &studentDetail[i].avgMark);

    }

    displayStudentDetails(studentDetail, 12);

    printf("\n\nProgrammed by Milan Bairagi");
}