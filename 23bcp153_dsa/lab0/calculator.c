#include <stdio.h>

int add(float a, float b);
int subtract(float a, float b);
int multiply(float a, float b);
int divide(float a, float b);

int main(void)
{
    float a;
    float b;
    char operation = '+';
    printf("Enter first number: ");
    scanf("%f", &a);
    printf("Enter second number: ");
    scanf("%f", &b);
    getchar();
    printf("Enter one of the operations from +, -, *, / : ");
    scanf("%c", &operation);
    switch (operation)
    {
        case '+':
            add(a, b);
            break;
        case '-':
            subtract(a, b);
            break;
        case '*':
            multiply(a, b);
            break;
        case '/':
            divide(a, b);
            break;
        default:
            printf("Invalid Input!");
            return 1;    
    }
    return 0;
}


int add(float a, float b)
{
    if (a <= 0 || b <= 0)
    {
        printf("The numbers should be positive!");
        return 1;
    }

    printf("Answer is : %.2f \n", a + b);
    return 0;
}

int subtract(float a, float b)
{
    if (a < b)
    {
        printf("First number must be greater than the second");
        return 1;
    }

    printf("Answer is : %.2f \n", a - b);
    return 0;
}

int multiply(float a, float b)
{
    if (a == 0 || b == 0)
    {
        printf("The number must not be equal to 0");
        return 1;
    }

    printf("Answer is : %.2f \n", a * b);
    return 0;
}

int divide(float a, float b)
{
    if (b == 0)
    {
        printf("The second number must not be equal to 0");
        return 1;
    }
    
    printf("Answer is : %.2f \n", a / b);
    return 0;
}
