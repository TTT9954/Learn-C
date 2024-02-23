#include <stdio.h>
#include <stdint.h>
#include "Point.h"


int main()
{
    Point a = Point_initialize(1.0,2.0);
    Point b = Point_initialize(3.0,4.0);

    //Print(&a);
    int choice = 0;
    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice <= 0 || choice > 2) printf("Your choice is not available! (1 or 2)\n");
    }while(choice <= 0 || choice > 2);
    switch (choice)
        {
        case 1:
            Print(&a);
            break;
        case 2:
            Print(&b);
            break;
        default:
            break;
        }
    return 0;  
}