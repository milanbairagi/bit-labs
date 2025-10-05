#include <stdio.h>

typedef struct student {
    char name[50];
    int marks;
    float cgpa;
    char course[50];

} std;

void writeData(std students[], int n, char filename[]);

int main() {
    std students[5] = {
        {"John Doe", 85, 3.5, "Computer Science"},
        {"Jane Smith", 78, 3.2, "Electrical Engineering"},
        {"Bob Johnson", 92, 3.9, "Mathematics"},
        {"Alice Brown", 75, 3.0, "Physics"},
        {"Charlie Wilson", 88, 3.7, "Chemistry"}
    };

    char *filename = "Details.txt";

    writeData(students, 5, filename);

    return 0;
}


void writeData(std students[], int n, char filename[]) {
    FILE *fout = fopen(filename, "w");

    fputs("+------------------+-------+------+-------------------------+\n", fout);
    fputs("| Name             | Marks | CGPA | Course                  |\n", fout);
    fputs("+------------------+-------+------+-------------------------+\n", fout);

    printf("+------------------+-------+------+-------------------------+\n");
    printf("| Name             | Marks | CGPA | Course                  |\n");
    printf("+------------------+-------+------+-------------------------+\n");

    for (int i = 0; i < n; i++) {
        char detail[200];
        snprintf(detail, 200, "| %-16s | %-5d | %-4.2f | %-23s |\n", students[i].name, students[i].marks, students[i].cgpa, students[i].course);

        fputs(detail, fout);
        printf("%s", detail);
    }
    
    fputs("+------------------+-------+------+-------------------------+\n", fout);
    printf("+------------------+-------+------+-------------------------+\n");

    fclose(fout);
}

