#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//Complete the following function.

void Input(int *a, int *n)
{
   
   printf("\nInput elements: ");
   for(int i=0; i< *n; i++)
   {
      scanf("%d", &a[i]);
   }
}

void Output(int *a, int n)
{
   for(int i=0; i<n; i++)
   {
      printf("%d ",*a);
      a++;   
   }
   printf("\n");
}

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Delete(int *a, int *n, int k)
{
    for(int i = k; i< *n-1; i++)
    {
        a = (a+1);
        a++; 
    }
    *n -= 1;
}

void Bubble_sort(int *a, int *n)
{
    for(int i=0; i<*n; i++)
    {
        for(int j=0; j<*n; j++)
        { 
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }   
        }
    }
}

void Selection_Sort(int *a, int *n)
{
    for(int i=0; i< *n;i++)
    {
        int min = i;
        for(int j=i+1; j<*n; j++)
        {
            if(a[j]<a[min]) min=j;
        }
        swap(&a[i],&a[min]);
    }
}

void Insertion_Sort(int *a, int *n)
{
    for(int i=0; i<*n; i++)
    {
        int j=i;
        while(j > 0 && a[j-1] > a[j])
        {
            swap(&a[j-1],&a[j]);
            j--;
        }
    }
}

void sum_max(int *a, int *n)
{
    int sum=0;
    int max = 0;
    for(int i=0; i< *n-1;i++)
    {
        sum=a[i]+a[i+1];
        if(sum > max) 
        {
            max = sum; 
        }
    }
    printf("\n%d", max);
}
/*void themvaocuoimang(int *a, int *n, int m)
{
    a[*n]=m;
    n++;
    Output(a,n);
}*/

/*void themvaodaumang(int *a, int *n, int m)
{ 
    *n += 1;
    for(int i=*n-1; i>0; i--)
    {
        a[i]=a[i-1];
    }
    a[0]=m;
}*/

/*void themphantu(int *a, int *n, int m, int vitri)
{
    *n += 1;
    for(int i=*n-1; i>=vitri ; i--)
    {
        a[i]=a[i-1];
        
    }
    a[vitri]=m;
}*/

/*int giaithua(int n)
{
    if(n==0) return 1;
    return n * giaithua(n-1);
}

int sum_giaithua(int n)
{
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        sum += giaithua(i);
    }
    return sum;
}*/
float maxmin(float a, float b, float c)
{
    float max;
    if(a<c && b<c)
    {
        max = c;
    }
    else if(a<b && c<b) max =  b;
    else max = a;
    return max;
}

int giatrimacdinh = 1;
int i = 1;
bool state1 = true;
int *a=NULL;

void increase(int count)
{
    if(count < 100)
    {
        (count)++;
        printf("Count: %d ",count);
    }
}

void display(int count)
{
    printf("Count: %d", count);
}
int main() { 
    int n;
    int count = 0;
    do
    {
       scanf("%d",&n); 
    } while (n<1);
    a=(int*) malloc(n * sizeof(int));
    Input(a,&n);
    printf("\nArray: \n");
    Output(a,n);
    Bubble_sort(a,&n);
    Output(a,n);
    return 0;

}