#include <stdio.h>
#include <string.h>

void sum(int a,int b)
{
    printf("sum : %d\n", a+b);
}

void sub(int a,int b)
{
    printf("sub : %d\n", a-b);
}

void mul(int a,int b)
{
    printf("mul : %d\n", a*b);
}

void di(int a,int b)
{
    printf("div : %3.2f", a/b);
}

int main()
{
    int choice = 0;
    int num1 = 0;
    int num2 = 0;
    printf("choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            sum(num1, num2);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            sub(num1, num2);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            mul(num1, num2);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            di(num1, num2);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}


