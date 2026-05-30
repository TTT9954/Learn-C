#include "struct3.h"
#include <stdio.h>
#include <stdint.h>


SUM_BILL bill[MAX];

static uint8_t count = 0;

void menu1(uint8_t *exit)
{   
    int choice;
    int choice_delete;
    printf("------- Bill summary application -------\n");
    printf("1. Add new bill\n");
    printf("2. Display all bill\n");
    printf("3. Delete existed bill by date\n");
    printf("0. Exit the application\n");
    printf("Enter your option: "); 
    do{
        scanf("%d", &choice);
        switch (choice)
        {
            case 0:
                *exit = 0; 
                printf("Exiting the application.....\n");          
                break;
            case 1:
                printf("****** Add new bill ******* (%d/100)\n", count);
                add_bill(bill, &count);
                break;
            case 2:
                printf("****** Display all bill ****** (%d/100)\n", count);
                display_bill(bill, &count);
                break;
            case 3:
                printf("****** Delete existed bill by date ******\n");
                printf("1. Delete day by day\n");
                printf("2. Delete whole list\n");
                printf("Enter your option: ");
                scanf("%d", &choice_delete);
                    switch (choice_delete)
                    {
                        case 1:                           
                            delete_bill(bill, &count);
                            break;
                        case 2:
                            delete_all(bill, &count);
                            break;                       
                        default:
                            break;
                    }
                break;    
            default:
                printf("Invalid option !\n"); 
                printf("Please enter your option: ");
                break;
        }
    }while(choice > 3 && *exit != 1);
}

void display_bill(SUM_BILL *bill, uint8_t *quantity)
{
    int i = 0;
    int sum = 0;
    if(*quantity == 0) printf("The list is empty\n");
    else
    {
        while(i < *quantity)
        {
            printf("%d. Date: %s - Bill: %d\n", i+1, bill[i].date, bill[i].price);
            sum += bill[i].price;
            ++i;
        }
        printf("Summary: %d\n", sum);
        
    }
    
}

void add_bill(SUM_BILL *bill, uint8_t *quantity)
{
    if(*quantity > MAX) 
    {
        printf("The list is full\n");
        printf("Please delete any records !\n");
        return;
    }
    else
    {   
        printf("Number of bill: %d\n", *quantity);
        printf("Enter your date: ");
        scanf("%s", bill[*quantity].date);
        fflush(stdin);
        printf("Enter your bill: ");
        scanf("%d", &bill[*quantity].price);
        (*quantity)++;
    }
}

void delete_bill(SUM_BILL *bill, uint8_t *quantity)
{
    int i = 0;
    int index_delete = -1;
    char delete_date[50];
    if(*quantity == 0) 
    {
        printf("The list is empty\n");
        return;
    }
    else
    {   
        printf("Enter your date to delete: ");
        scanf("%s", delete_date);
        fflush(stdin);
        while(i <= *quantity)
        {
            if(strcmp(bill[i].date, delete_date) == 0)
            {
                index_delete = i;
            }
            i++;
        }
        if(index_delete == -1) printf("Not found date \n");
        else
        {
            i = index_delete;
            while(i < *quantity)
            {
                bill[i] = bill[i+1];
                i++;
                
            }
            --*quantity;         
        }
    }
}

void delete_all(SUM_BILL *bill, uint8_t *quantity)
{
    for(uint8_t i = 0; i < *quantity; i++)
    {
        memset(&bill[i],0,sizeof(SUM_BILL));
        *quantity = 0;
    }
}