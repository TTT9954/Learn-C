#include <stdio.h> 

void pattern_1(int n);
void pattern_2(int n);
void pattern_3(int n);
void pattern_4(int n);
void pattern_5(int n);
void pattern_6(int n);
void pattern_7(int n);
void pattern_8(int n);
void pattern_9(int n);
void pattern_10();

int main()
{
    int n;
    // printf("Enter number of rows: ");
    // scanf("%d", &n);
    pattern_10();
    return 0;
}

void pattern_1(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= n; col++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void pattern_2(int n)
{
    int number = 1;
    int alphabet = 65;
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= row; col++)
        {
            //printf("* ");
            printf("%c ", alphabet);
        }
        alphabet++;
        printf("\n");
    }
}

void pattern_3(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= n-row+1; col++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void pattern_4(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= row; col++)
        {
            printf("%d ", col);
        }
        printf("\n");
    }
}

void pattern_5(int n)
{   
    // row = 2n-1
    for(int row = 1; row <= 2*n-1; row++)
    {
        int totalCol = (row > n ? 2*n-row : row);
        for(int col = 1; col <= totalCol; col++)
        {
            printf("%d", col);
        }
        printf("\n");
        /* if(row > n)
        {
           for(int col = 1; col <= 2*n-row; col++)
            {
                printf("* ");
            } 
        }
        else 
        {

            for(int col = 1; col <= row; col++)
            {
                printf("* ");
            }
        }
        printf("\n") */;
    }
}

void pattern_6(int n)
{
    for(int row = 1; row <= n; row++)
    {
        //int space = n - row;
        for(int col = 1; col <= n; col++)
        {
            if(col > n-row) printf("*");
            else printf(" ");
        } 
        printf("\n");
    }
}

void pattern_7(int n)
{
    for(int row = 1; row <= n; row++)
    {
        int space = row-1;
        for(int col = 1; col <= n; col++)
        {
            if(col > space) printf("*");
            else printf(" ");
        } 
        printf("\n");
    }
}

void pattern_8(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= 2*n-1; col++)
        {
            // if(col <= n-row || col >= n+row) printf(" ");
            //else printf("*"); 
            if(col > n-row && col < n+row) printf("%d ",col);
            else printf("  ");
        }
        printf("\n");
    }
}

void pattern_9(int n)
{
    int k;
    for(int row = 1; row <= n; row++, k=0)
    {
        /* for(int col = 1; col <= 2*n-1; col++)
        {
            //if(col <= row - 1 || col > 2*n-row) printf(" ");
            //else printf("*");
            if(col > row-1 && col <= 2*n-row) printf("*");
            else printf(" ");
        } */
        printf("\n");
    }
}

void pattern_10()
{
    for(int i = 1; i<=5; i++)
    {
        for(int j = 1; j <= 23; j++)
        {
            if((j == 11) || (i == 1 && (j >= 9 && j <= 13)) || (i == 5 && (j >= 9 && j <= 13)))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 1; i<= 5; i++)
    {
        for(int j = 1; j <= 23; j++)
        {
            if(j == 1 || (i == 5 && (j>=1 && j<=5)) 
               || (i == 1 && (j >= 7 && j <= 11)) || (i == 5 && (j >= 7 && j <= 11)) 
               || ((i >= 2  && i <= 4) && (j == 7 || j == 11))
               || ((i >= 1 && i <= 3) && (j == 13 || j == 17)) || (i == 4 && (j == 14 || j == 16) || (i==5 && j == 15))
               || ( j == 19 || ((i == 1 || i == 3 || i == 5) && (j >= 19 && j <= 23))))
            {
                printf("*");
            }
            
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 1; i<=5; i++)
    {
        for(int j = 1; j <= 23; j++)
        {
            if(((i == 1 && (j == 3 || j == 7)) || (i == 2 && (j == 4 || j == 6)) || ((i >= 3 && i <= 5) && j == 5))
                || ((i == 1 || i == 5) && (j >= 9 && j <= 13)) || ((i >= 2 && i <= 4) && (j == 9 || j == 13))
                || ((j == 15 || j == 19) || (i == 5) && (j >= 15 && j<=19)))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");

}