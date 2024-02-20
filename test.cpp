#include <stdio.h>
#include <string.h>
#include <conio.h>


struct Date
{
   char Name[20];
   char ID[20];
   int Score;
}; 
void Input(struct Date *D)
{
   printf("\nInput student information \n");
   fflush(stdin);
   printf("Name: ");
   gets(D->Name);
   printf("ID: ");
   gets(D->ID);
   printf("Score: ");
   scanf("%d",&D->Score);
}

void Output(struct Date *D)
{
   printf("\n ------- Information -------- \n");
   printf("\nName: %s", D->Name);
   printf("\nID: %s", D->ID);
   printf("\nScore: %d", D->Score);
}

int main()
{
    int a;
    int *p;
    p = new int;
    *p = 10;
    delete p;
}