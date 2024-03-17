#include <stdio.h>
#include <stdint.h>
#include <math.h>
int main()
{
    int number;
    int count = 0;
    int digit = 0;
    int sum = 0;
    printf("Enter number: ");
    scanf("%d",&number);
    int temp = number;
    int result = 0;
    while(temp > 0)
    {
        digit = temp % 10;
        temp /= 10;
        ++count;
    }
    printf("Digit: %d\n", count);
    temp = number;
    while(temp > 0)
    {
        digit = temp % 10;
        temp /= 10;
        sum = sum + pow(digit,count);
        
    }
    if(sum == number) printf("%d is the armstrong number\n", number);
    else printf("%d is not the armstrong number\n", number);
}