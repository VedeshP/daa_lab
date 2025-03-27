#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[30];
    int roll_no;
    float cgpa;
}
Student;

int main(void)
{
    Student s1;

    Student *ptr;

    ptr = &s1;

    printf("Enter Student's Name: ");
    fgets(ptr->name, sizeof(ptr->name), stdin);
    ptr->name[strcspn(ptr->name, "\n")] = 0; 

    printf("Enter Student's Roll No.: ");
    scanf("%d", &ptr->roll_no);

    printf("Enter CGPA of Student: ");
    scanf("%f", &ptr->cgpa);

    printf("\nStudent Details:\n");
    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->roll_no);
    printf("Grade: %.2f\n", ptr->cgpa);

    return 0;
}

// https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input