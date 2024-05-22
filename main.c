#include "inc/main.h"
#include "inc/String.h"
#include "inc/Array.h"

#define YEARS   5
#define MONTHS  12
int main(int argc, char *argv[])
{
   float RainFall[YEARS][MONTHS] = 
      {// JAN  FEB  MAR  APR  MAY  JUN  JUL AUG  SEP  OCT  NOV  DEC
         {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
         {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3}, 
         {0.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.41}, 
         {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2}, 
         {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2} 
      };

   float sum_each_month = 0.0f;
   float sum_each_year = 0.0f;
   float sum_5years = 0.0f;
   float average_each_month = 0.0f;
   float average_each_year = 0.0f;
   float average_5years = 0.0f;

   int year = 0;
   int month = 0;

   // Display all data
   for(year = 0; year < YEARS; year++)
   {

   }
   
   for(year = 0; year < YEARS; year++)
   {
      sum_each_month = 0;
      for(month = 0; month < MONTHS; month++)
      {
         sum_each_month += RainFall[year][month];
      }
      printf("%d: %.2f", year+2011, sum_each_month);
      sum_5years += sum_each_month;
      printf("\n");
   }
   printf("Sum in 5 years: %.2f\n", sum_5years);
   average_5years = (float)sum_5years/(float)5;
   printf("Average in 5 years: %.2f\n", average_5years);

   printf("--- Average monthly in 5 years ---\n");
   printf("JAN\tFEB\tMAR\tAPR\tMAY\tJUN\tJUL\tAUG\tSEP\tOCT\tNOV\tDEC\n");
   for(month = 0; month < MONTHS; month++)
   {
      sum_each_month = 0;
      for(year = 0; year < YEARS; year++)
      {
         sum_each_month += RainFall[year][month];
      }
      printf("%.2f\t", sum_each_month);
      sum_5years += sum_each_month;  
   }
   
   average_each_month = sum_5years/MONTHS;
   printf("\nAverage monthly in 5 years: %.2f\n", average_each_month);


   int spec_year = 0;
   int temp = 0;

   printf("--- Display rainfall in the specific year--- \n");
   printf("Enter specific year: ");
   scanf("%d", &spec_year);
   do{
         switch (spec_year)
         {
            case 2011:
               temp = 0;
               break;
            case 2012:
               temp = 1;
               break;
            case 2013:
               temp = 2;
               break;
            case 2014:
               temp = 3;
               break;
            case 2015:
               temp = 4;
               break;
            default:
               printf("Please enter between 2011-2015: ");
               scanf("%d", &spec_year);
         }
   }while(spec_year > 2015 || spec_year < 2011);
   

   printf("JAN\tFEB\tMAR\tAPR\tMAY\tJUN\tJUL\tAUG\tSEP\tOCT\tNOV\tDEC\n");
   for(int i = 0; i < 1; i++)
   {
      for(int j = 0; j < MONTHS; j++)
      {
         printf("%.2f\t", RainFall[temp][j]);
      }
   }

   

   return 0;
}

