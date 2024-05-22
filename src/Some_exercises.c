#include "../inc/Array.h"

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME     40

void salary_cal(double hour)
{
   double NumberOfHours = hour;
   double GrossPay = 0;
   double NetPay = 0;
   double Tax = 0;

   if(NumberOfHours <= OVERTIME) 
   {
      GrossPay = (double)NumberOfHours * PAYRATE;
   }
   else 
   {
      GrossPay = (40 * PAYRATE);
      double OvertimePay = (NumberOfHours - 40) * (1.5 * PAYRATE);
      GrossPay = GrossPay + OvertimePay;
   }

   if(GrossPay <= 300) 
   {
      Tax = GrossPay * TAXRATE_300;
   }
   else if(GrossPay > 300 && GrossPay <= 450)
   {
      Tax = 300 * TAXRATE_300;
      Tax += (GrossPay - 300) * TAXRATE_150; 
   }
   else if(GrossPay > 450) 
   {
      Tax = 300 * TAXRATE_300;
      Tax += 150 * TAXRATE_150;
      Tax += (GrossPay - 450) * TAXRATE_REST;
   }
   
   NetPay = GrossPay - Tax;

   printf("%lf\n", GrossPay);
   printf("%lf\n", Tax);
   printf("%lf\n", NetPay);
}

int GuessNumberGame()
{
   time_t t;

   int GuessedNumber = 0;
   int count_left = 0;
   int randomNumber = 0;
   int NumberOfGuesses = 5;
   // Initialization of random number generator

   printf("This is the guessing game.\n");
   printf("I have chosen a number between 0-20 which you must guess. \n");

   for(NumberOfGuesses = 5; NumberOfGuesses > 0 ; NumberOfGuesses--)
   {
      randomNumber = rand()%21;
      printf("\nYou have %d tr%s left\n", NumberOfGuesses, (NumberOfGuesses == 1 ? "y" : "ies"));
      printf("Enter guess Number: ");
      scanf("%d", &GuessedNumber);
      if(GuessedNumber == randomNumber) 
      {
         printf("You are win\n"); 
         return 1;
      }
      else if(GuessedNumber < 0 || GuessedNumber > 20)
      {
         printf("I said the guess number between 0-20 !");
      }
      else if(randomNumber > GuessedNumber)
      {
         printf("Sorry, %d is wrong. My number is greather than that.\n", GuessedNumber);
      }
      else if(randomNumber < GuessedNumber)
      {
         printf("Sorry, %d is wrong. My number is less than that.\n", GuessedNumber);
      }
   }
   printf("You have had 5 tries and failed. The number was: %d", randomNumber);
   return 0;
}

void PrimesArray(int n)
{
   int primesArray[50] = {0};
   int p = 0;
   int IsPrime = 1;
   int size = sizeof(primesArray)/sizeof(primesArray[0]);
   int primeIndex = 2;
   
   primesArray[0] = 2;
   primesArray[1] = 3;
   for(p = 5; p < n; p += 2)
   {
      IsPrime = 1;
      for(int j = 2; j < p/2; j++)
      {
         if(p%j == 0) 
         {
            IsPrime = 0;
            break;
         }
      }
      if(IsPrime == 1) 
      {  
         primesArray[primeIndex] = p;
         primeIndex++;
      }
   }

   Output(primesArray, &primeIndex);
}