/*
Write a program to sort string words stored in an array of pointers.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sorter(int,char **);

int  main() {
    char *string[20];
    int n;
    printf("Enter no. of String: ");
    scanf("%d",&n);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the Strings %d: ",i+1);
        string[i] = (char *)malloc(20*sizeof(char));
        scanf("%s", string[i]);
    }

    sorter(n, string);

    printf("\nreorder list is:  \n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n",i+1,string[i]);
    }
    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}

void sorter(int n, char *x[]){
    char t[20];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(x[i], x[j]) > 0){
                strcpy(t, x[j]);
                strcpy(x[j], x[i]);
                strcpy(x[i], t);
            }
        }
    }
}
  