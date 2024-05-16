#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "string1.h"

#define LENGTH   10

int get_MAX(const int a)
{
    static int max = 0;
    return ((a > max) ? a : max);
}
int *Input()
{
    static int arr[LENGTH] = {0};
    for(int i = 0; i < LENGTH; i++)
    {
        scanf("%d", arr+i);
    }
    return arr;
}

int Output(const int arr[])
{
    for(int i = 0; i < LENGTH; i++)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int string_compare(char a[], char b[])
{
    if((strlen(a) > strlen(b)) || (strlen(b) > strlen(a)))
    {
        return -1;
    }
    while((*a != 0))
    {
        if(*a++ != *b++) return 1;
    }
    return 0;
}

char *reverse_string(char *s)
{
    char c;
    for(int i = 0, j = strlen(s)-1; i <= j; i++, j--)
    {
        c = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = *(s+i);
    }
    return s;
}

char *delete_character(char s[], char c)
{
    int delete_index;
    int length = strlen(s);
    for(int i = 0; i < length; i++)
    {
        if(s[i] == c)
        {
            delete_index = i;   
            for(int i = delete_index; i < length; i++)
            {
                s[i] = s[i+1];
            }
            length--;
        }
    }
    return s;
}

char *delete_word(char *s, char *word)
{
    int delete_index;
    int temp_index;
    char *temp_word;
    int length = strlen(s);
    for(int i = 0; i < length; i++)
    {
        temp_word[i] = s[i];
        if(s[i] == ' ')
        {
            i+= 1;
        }
    }
    return s;
}

int MaxMin_array(int a[], char s[])
{
    int max = 0;
    int min = a[0];
    char *max_s = "max";
    char *min_s = "min";

    if(!string_compare(max_s, s))
    {
        for(int i = 0; i < LENGTH; i++)
        {
            if(a[i] > max) max = a[i];
        }
        return max;
    }
    else if(!string_compare(min_s, s))
    {
        for(int i = 0; i < LENGTH; i++)
        {
            if(min > a[i]) min = a[i];
        }
        return min;
    }

    return -1;
}



void print_string(char s[])
{
    while(1)
    {
        if(*s == '\0')
        {
            printf("%c", ' ');
            break;
        }
        printf("%c", *s++);
    }
}

void concat_string(char destination[], const char *soure)
{
    int length1 = strlen(destination);
    int length2 = strlen(soure);
    for(int i = 0; soure[i] != '\0'; i++)
    {
        destination[length1++] = soure[i];
    }
    destination[length1] = '\0';
}

int main()
{
    int *arr = NULL;

    char a[] = "Hello";
    char b[] = "Error";

    char str[] = {0};

    print_string(a);

    return 0;
}