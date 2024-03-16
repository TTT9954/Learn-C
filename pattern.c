#include <stdio.h> 

void pattern_1(int n);
void pattern_2(int n);
void pattern_3(int n);
void pattern_4(int n);
void pattern_5(int n);
void pattern_6(int n);
void pattern_7(int n);
void pattern_8(int n);

int main()
{
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    pattern_8(n);
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
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= row; col++)
        {
            printf("* ");
        }
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
            printf("* ");
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
            if(col > n-row && col < n+row) printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}