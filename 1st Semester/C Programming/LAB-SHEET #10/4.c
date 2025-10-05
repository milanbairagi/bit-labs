/*
Write name, age and height of a person into a data
file “person.txt” and read it (use fprintf () and fscanf()
function).
*/

#include <stdio.h>
#include <string.h>


int main() {
    char name[50];
    int age;
    float height;

    // Get user input
    printf("Enter name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline from name

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter height (in cm): ");
    scanf("%f", &height);

    // Open file for writing
    FILE *fp = fopen("person.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    // Write data to file using fprintf
    fprintf(fp, "%s %d %.2f\n", name, age, height);

    fclose(fp); // Close file after writing

    // Open file for reading
    fp = fopen("person.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    // Read data from file using fscanf
    fscanf(fp, "%s %d %f", name, &age, &height);

    fclose(fp); // Close file after reading

    // Display read information
    printf("\nPerson information:\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f cm\n", height);

    printf("\nProgrammed by Milan Bairagi");

    return 0;
}
