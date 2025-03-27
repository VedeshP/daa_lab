#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[30];
    int roll_no;
    char address[100];
} 
Student;

int main(void)
{
    Student students[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %s", students[i].name);
        printf("Enter the roll no of student %d: ", i + 1);
        scanf("%d", &students[i].roll_no);
        printf("Enter the address of student %d: ", i + 1);
        scanf(" %s", students[i].address);
    }


    printf("\nStudent Details:\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Address: %s\n\n", students[i].address);
    }

    return 0;
}