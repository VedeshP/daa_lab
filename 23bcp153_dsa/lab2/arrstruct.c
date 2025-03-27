#include <stdio.h>

#define ORGANIZATIONS 2
#define EMPLOYEES 2

typedef struct Employee
{
    char name[30];
    float salary;
    int id;
}
Employee;


typedef struct Organization {
    int name[30];
    int id;
    Employee employees[2];
}
Organization;

int main(void)
{
    Organization organizations[2];

     for (int i = 0; i < ORGANIZATIONS; i++) {
        printf("Enter the name of organization %d: ", i + 1);
        scanf("%s", organizations[i].name);
        printf("Enter the ID of organization %d: ", i + 1);
        scanf("%d", &organizations[i].id);

        for (int j = 0; j < EMPLOYEES; j++) {
            printf("\tEnter the name of employee %d in organization %d: ", j + 1, i + 1);
            scanf("%s", organizations[i].employees[j].name);
            printf("\tEnter the ID of employee %d in organization %d: ", j + 1, i + 1);
            scanf("%d", &organizations[i].employees[j].id);
            printf("\tEnter the salary of employee %d in organization %d: ", j + 1, i + 1);
            scanf("%f", &organizations[i].employees[j].salary);
            printf("\n");
        }
    }

    printf("\nOrganization Details:\n");
    for (int i = 0; i < ORGANIZATIONS; i++) {
        printf("Organization %d:\n", i + 1);
        printf("Name: %s\n", organizations[i].name);
        printf("ID: %d\n", organizations[i].id);

        for (int j = 0; j < EMPLOYEES; j++) {
            printf("\tEmployee %d:\n", j + 1);
            printf("\tName: %s\n", organizations[i].employees[j].name);
            printf("\tID: %d\n", organizations[i].employees[j].id);
            printf("\tSalary: %.2f\n", organizations[i].employees[j].salary);
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}