#include "../inc/String.h"

int count_char(char *s)
{
    int count=0, i=0;
    for(i=0; *s!=0 ; i++)
    {
        if (*s != ' ')
        {
            count++;
        }
        *s++;
    }
    return count;
}

void count_word(char s[30])
{
    int count = 0;
    if(s[0]!= ' ')
    {
        count++;
    }
    for(int i=0; i< strlen(s)-1; i++)
    {
        if(s[i]==' ' && s[i+1] !=' ')
        {
            count++;
        }
    }
    
    printf("A number of words in the string: %d ", count);
}

void Delete(char s[30], int vitri)
{
    int lenght=strlen(s);
    for(int i=vitri; i<strlen(s) ; i++)
    {
        s[i]=s[i+1];
    }
    lenght --;
    printf("%s\n", s);
}

void Add(char s[30], char k, int vitri)
{
    int length=strlen(s);
    length++;
    for(int i=length-1; i>=vitri; i--)
    {
        s[i+1]=s[i];
    }
    s[vitri]=k;
    printf("%s\n", s);
}

void hoa_thuong(char s[30])
{
    int length=strlen(s);
    for(int i=0; i<length; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        else if (s[i] >= 'a' && s[i] <= 'z')  s[i] -= 32;
    }
    printf("%s ", s);
}

void invert(char s[30])
{
    int length=strlen(s);
    for(int i=0; i< length/2; i++)
    {
        char temp=s[i];
        s[i]=s[length-i-1];
        s[length-i-1]=temp;
    }
    printf("%s",s);
}

char *reverse(char s[])
{
    char c;
    for(int i = 0, j = strlen(s)-1; i <= j; i++, j--)
    {
        c = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = c;
    }
    return s;
}

char *concat(char s1[], char s2[])
{
    for(int i = 0; i < strlen(s2); i++)
    {
        int len1 = strlen(s1);
        s1[len1++] = s2[i];
    }

    return s1;
}

int strcmp1(char s1[], char s2[])
{
    int sum = 0;
    while(*s1 != '\0' || *s2 != '\0')
    {
        if(*s1++ != *s2++) return 1; 
    }
    return 0;
}
