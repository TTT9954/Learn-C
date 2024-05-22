#include "../inc/Array.h"

void Input(int a[], int *size)
{
    if(*size > MAX_LENGTH) return;
    for(int i = 0; i < *size; i++)
    {
        scanf("%d", &a[i]);
    }
}

void Output(const int arr[], int *size)
{
    if(*size > MAX_LENGTH) return;
    for(int i = 0; i < *size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int swap(int *a, int *b)
{
    int temp = 0;
    temp =  *a;
    *a = *b;
    *b = *a;
}

int Search(int a, int x)
{
    if(a == x) return 1;
    return 0;
}

int LinearSearch(int a[], int *size, int x)
{
    for(int i = 0; i < *size; i++)
    {
        if(a[i] == x)
        {
            return 1;
        }
    }
    return -1;
}

int BinarySearch(int a[], int *size, int x)
{
    int mid = 0;
    int left = 0;
    int right = *size-1;
    for(int i = left; left <= right;)
    {
        mid = (left+right)/2;
        if(a[mid] == x)
        {
            return 1;
        }
        else if(a[mid] > x)
        {
            right = mid - 1;
        }
        else if(a[mid] < x)
        {
            left = mid + 1;
        }
    }
    return -1;
}

int BinarySearch1(int a[], int *size, int x)
{
    int mid = 0;
    int left = 0;
    int right = *size-1;
    for(int i = left; left < right;)
    {
        mid = (left+right)/2;
        if(a[mid] == x)
        {
            return mid;
        }
        else if(a[mid] > x)
        {
            right = mid - 1;
        }
        else if(a[mid] < x)
        {
            left = mid + 1;
        }
    }
    return -1;
}

int Count_Freq_Appear(int a[], int *size, int x)
{
    int count = 0;
    for(int i = 0; i < *size; i++)
    {
        if(Search(a[i], x))
        {
            count++;
        }
    }
    return count;
}

void BubbleSort(int a[], int *size)
{
    for(int i = 0; i < *size; i++)
    {
        for(int j = i+1; j < *size; j++)
        {
            if(a[i] > a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
}

void Element_Addition(int a[], int *size, int element_add, int pos)
{
    *size = *size + 1;
    for(int i = *size - 1; i >= pos; i--)
    {
        a[i] = a[i-1];
    }
    a[pos] = element_add;
}

int Delete_Element(int *a, int *size, int element_del)
{
    int is_del = 0;
    int index_del = 0;
    for(int i = 0; i < *size; i++)
    {
        if(Search(a[i], element_del))
        {
            is_del = 1;
            index_del = i;
        }
        
    }
    if(is_del == 1)
    {      
        for(int i  = index_del; i < *size-1; i++)
        {
            a[i] = a[i+1];
        }  
        *size = *size - 1;        
    }
    
    return is_del;
}

void sum_array(int arr1[], int arr2[], int *size)
{
    int sum[MAX_LENGTH];
    for(int i = 0; i < *size; i++)
    {
        sum[i] = arr1[i] + arr2[i];
    }

    Output(sum, size);
}

void reverse_array(int a[], int *size)
{
    int temp = 0;
    int length = *size;
    for(int i = 0; i < *(size)/2; i++)
    {
        temp = a[i];
        a[i] = a[length-1];
        a[length-1] = temp;
        length--;
    }
}
