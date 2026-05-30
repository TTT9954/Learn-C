#include "Common_Func.h"

void IntToStr(char *str, uint32_t number)
{
   uint32_t temp = number;
   uint8_t n = 0;
   uint8_t i = 0;
   uint32_t div = 0;
   while(temp > 9)
   {
      n++;
      temp/=10;
   }
   temp = number;
   while (i < (n+1))
   {
      div = (uint32_t)pow(10, (n-i));
      if(i == 0)  
      {
         *str = ((temp/div))+ '0';
      }
      else *str = ((temp/div)%10)+ '0';
      str++;
      i++;
   }

   str[i] = '\0';
}

void tostring(char *str, int num)
{
    int i, rem, len = 0, n;
 
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

void FrequentlyElement(const uint8_t *arr, int length)
{
   int occurence  = 1;
   int i = 0;
   int j = 0;

   for(i = 0; i < length-1; i++)
   {
      for(j = i+1; j < length; j++)
      {
         if(*(arr+i) == *(arr+j))
         {
            occurence++;
         }
      }
      printf("%u-%u", *(arr+i), occurence);
      printf("\n");
   }
}

uint8_t SecondSmallest(uint8_t *arr, int length)
{
   
   uint8_t smallest = 0;
   uint8_t SecSmallest = 0;

   if(*arr < *(arr+1))
   {
      smallest = *arr;
      SecSmallest = *(arr+1);
   }
   else 
   {
      smallest = *(arr+1);
      SecSmallest = *(arr);
   }
   for(uint8_t *p = arr+2; p != (arr+length); p++)
   {
      if(*p < smallest) 
      {
         SecSmallest = smallest;

         smallest = *p;
      }
      else if(*p < SecSmallest && *p > smallest)
      {
         SecSmallest = *p;
      }

     
   }
   return SecSmallest;
}

uint8_t max_sum(uint8_t a[], int size)
{
   uint8_t sum  = 0;
   if(size <= 1) return 0;

   sum = a[0]+a[1];

   max_sum(a+1, size-1);
}