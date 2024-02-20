#include <stdio.h>
#include <string.h>
#include <conio.h>


struct student 
{
   char Name[20];
   char ID[20];
   int Score;
}; 
typedef struct student st;

void Input(st *st1)
{
   printf("\nInput student information \n");
   fflush(stdin);
   printf("Name: ");
   gets(st1->Name);
   printf("ID: ");
   gets(st1->ID);
   printf("Score: ");
   scanf("%d",&st1->Score);
}

void Output(st *st1)
{
   
   printf("\nName: %s", st1->Name);
   printf("\nID: %s", st1->ID);
   printf("\nScore: %d", st1->Score);
}

int main()
{
   st D1, D2;
   Input(&D1);
   Input(&D2);
   printf("\n ------- Information -------- \n");
   Output(&D1);
   Output(&D2);
   

   return 0;
}