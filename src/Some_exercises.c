#include "../inc/Array.h"
#include "../inc/main.h"
#include "../inc/String.h"

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

void count_rainfall()
{
      float RainFall[YEARS][MONTHS] = 
      {// JAN  FEB  MAR  APR  MAY  JUN  JUL AUG  SEP  OCT  NOV  DEC
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
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
   for(int i = 0; i < 100; i++)
   {
      printf("-");
   }
   printf("\n|YEAR|JAN\tFEB\tMAR\tAPR\tMAY\tJUN\tJUL\tAUG\tSEP\tOCT\tNOV\tDEC|\n");
   printf("|----|---------------------------------------------------------------------\n");
   for(year = 0; year < YEARS; year++)
   {
      printf("|%d|\n", year+2011);
      for(month = 0; month < MONTHS; month++)
      {

      }
   }
   printf("YEAR\tRAINFALL (inches)\n");
   for(year = 0; year < YEARS; year++)
   {
      sum_each_month = 0;
      for(month = 0; month < MONTHS; month++)
      {
         sum_each_month += RainFall[year][month];
      }
      printf("%d\t %.1f", year+2011, sum_each_month);
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
      printf("%.2f\t", sum_each_month/YEARS);
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

}

int gcd(int a, int b)
{
   int temp = 0;
   if(a > b) 
   {
      while(b != 0)
      {
         temp = a % b;
         a = b;
         b = temp;
      }
      temp = a;
   }
   else if(b > a)
   {
      while(a != 0)
      {
         temp = b % a;
         b = a;
         a = temp;
      }
      temp = b;
   }

   return temp;
}

float absolute(float a)
{
   if(a < 0) 
   {
      a = -a;
   }
   return a;
}

float squareRoot(float x)
{
    const  float  epsilon = .00001;
    float  guess   = 1.0;
    float returnValue = 0.0;

    if ( x < 0 )
    {
        printf ("Negative argument to squareRoot.\n");
        returnValue = -1.0;
    }
    else
    {
        while  ( absolute(guess * guess - x) >= epsilon )
           guess = ( x / guess + guess ) / 2.0;

        returnValue = guess;
    }

    return returnValue;
}

/* Tic tac toe game*/

void drawTable(char a[ROW][COL])
{   
   system("cls");
   for(int i = 0; i < ROW; i++)
   {
      for(int j = 0; j < COL; j++)
      {
         printf("| %c ", a[i][j]);
         if(j == COL-1) printf("|\n");
      }
      printf("|___|___|___|\n");
   }
}

void resetTable(char a[ROW][COL])
{
   char table[ROW][COL] = {'1', '2', '3',
                  '4', '5', '6',
                  '7', '8', '9'};

   for(int i = 0; i < ROW; i++)
   {
      for(int j = 0; j < COL; j++)
      {
         a[i][j] = table[i][j];
      }
   }
}

int checkWin(char a[ROW][COL])
{
   int returnValue = 0;
   
   for(int i = 0, j = 0; i < ROW && j < COL; i++, j++)
   {
      // check row
      if(a[i][0] == a[i][1] && a[i][1] == a[i][2])
      {
         returnValue = 1;
      }
      // check col
      else if(a[0][j] == a[1][j] && a[1][j] == a[2][j])
      {
         returnValue = 1;
      }
   }

   if((a[0][0] == a[1][1] && a[1][1] == a[2][2]) || (a[0][2] == a[1][1] && a[1][1] == a[2][0]))
   {
      returnValue = 1;
   }

   return returnValue;
}

int checkFreeSpace(char a[ROW][COL])
{
   int freeSpace = 9;
  
   for(int i = 0; i < ROW; i++)
   {
      for(int j = 0; j < COL; j++)
      {
         if(a[i][j] != '1' && a[i][j] != '2' && a[i][j] != '3' && a[i][j] != '4' && a[i][j] != '5'
             && a[i][j] != '6' && a[i][j] != '7' && a[i][j] != '8' && a[i][j] != '9')
         {
            freeSpace--;
         }
      }
   }
   return freeSpace;
}

int playerChoice(int *player, int *playerChoice)
{
   printf("Player %d enter the choice: ", *player+1);
   scanf("%d", playerChoice);

   return *playerChoice;
}

void playerMove(char a[ROW][COL], int *player)
{
   int x;
   int y;
   char mark;
   printf("Player %d turn \n", *player+1);

   printf("Enter ROW and COL number (x - y): "); 
   scanf("%d %d", &x, &y);

   while(x > 2 || y > 2)
   {
      printf("Invalid ROW or COL number\n");

      printf("Enter ROW and COL number (x - y) again: "); 
      scanf("%d %d", &x, &y); 
   }

   mark = ((*player+1) == 1) ? 'X' : 'O';

   if(a[x][y] == 'X' || a[x][y] == 'O')
   {
      printf("Invalid move\n");
      *player = *player - 1;
   }
   else a[x][y] = mark;
}

void fileExercise(FILE *file, FILE *fileTemp)
{
   int c = 0;
   int i = 0;
   char strW[30];
   char tempStr[30];

   printf("Enter your string: ");
   gets(strW);

   file = fopen(FILE_BASE, "w");

   if(file == NULL) return;

   while(i < (strlen(strW) + 1))
   {
      fputc((int)strW[i], file);
      i++;
   }

   fclose(file);

   file = fopen(FILE_BASE, "r");

   if(file == NULL) return;

   fileTemp = fopen("temp.txt", "w");

   if(fileTemp == NULL) return;

   while((c = fgetc(file)) != EOF)
   {
      c = upperChar((char)c);
      fputc(c, fileTemp);
   }
 
   fclose(file);
   fclose(fileTemp);

   remove(FILE_BASE);

   rename("temp.txt", FILE_BASE);

   remove("temp.txt");

   file = fopen(FILE_BASE, "r");

   if(file == NULL) return;

   while((c = fgetc(file)) != EOF)
   {
      printf("%c", c);
   }
   printf("\n");

   int len = ftell(file);

   c = 0;
   i = 0;
   len = len - 2;
   fseek(file, len, SEEK_SET);

   while(len >= 0)
   {
      c = fgetc(file);
      tempStr[i] = (char)c;
      i++;
      len--;
      fseek(file, len, SEEK_SET);
   }

   tempStr[i] = '\0';

   printf("%s", tempStr);

   fclose(file);

   file = NULL;
   fileTemp = NULL;
}