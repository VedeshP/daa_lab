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
    Student s1;
    printf("Enter the name of the student: ");
    scanf("%s", &s1.name);
    printf("Enter the roll no of the student: ");
    scanf("%d", &s1.roll_no);
    printf("Enter the address of the student: ");
    scanf("%s", &s1.address);

    printf("%s\n", s1.name);
    printf("%d\n", s1.roll_no);
    printf("%s\n", s1.address);

    return 0;
}