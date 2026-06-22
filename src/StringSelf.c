#include "StringSelf.h"

bool isSpace(char c)
{
   if(c = ' ')
   {
      return 1;
   }
   return 0;
}

int count_char_noSpace(char *s)
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

int countChar_withSpace(const char s[])
{
   int count = 0;
   while(*s++ != '\0')
   {
      ++count;
   }
   return count;
}

int count_word(char s[30])
{
    int count = 0;
    if(s[0]!= ' ')
    {
        count++;
    }
    for(int i=0; i< strlen(s)-1; i++)
    {
        if(s[i]== ' ' && s[i+1] !=' ')
        {
            count++;
        }
    }
    
    return count;
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

char *Add_char(char s[30], char k, int pos)
{
    int length = strlen(s);
    char temp_c = 0;
    length++;
    for(int i=pos; i < length; i)
    {
        s[length] = s[length-1];
        length--;
    }
    s[pos]=k;
    return s;
}

char upperChar(char c)
{
    if (c >= 'a' && c <= 'z') 
    {
        c -= 32;
    }
    return c;
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

int StringCompare(const char s1[], const char s2[])
{
   int i = 0;
   int length_1 = countChar_withSpace(s1);
   int length_2 = countChar_withSpace(s2);
   int equalCheck = 1;
   int validCheck = 0;
   validCheck = (length_1 == length_2) ? 0 : (length_1 > length_2) ? (length_1 - length_2) : (length_2 - length_1);
   if(validCheck > 0 && equalCheck == 1)
   {
      return (length_1 - length_2);
   }
   else if (validCheck < 0 && equalCheck == 1)
   {
      return (length_2 - length_1);
   }
   else if(equalCheck  == 1 && validCheck == 0)
   {
      while(s1[i] != '\0' && s2[i] != '\0')
      {
         if(s1[i] == s2[i])
         {
            if(s1[i+1] != s2[i+1] && s1[i+1] > s2[i+1])
            {
               return s1[i+1] - s2[i+1];
            }
            else if(s1[i+1] != s2[i+1] && s1[i+1] < s2[i+1])
            {
               return s1[i+1] - s2[i+1];
            }
         }
         else
         {
            return s1[i] - s2[i];
         }
         i++;
      }
      if(s1[i] == '\0' && s2[i] == '\0')
      {
         equalCheck = 0;
      }

   }

   return equalCheck;
}

int isDigit(char c)
{
   if((c < 48) || (c > 57))
   {
      return 0;
   }
   return 1;
}

int isAlpha(char c)
{
   if(((c < 65) || (c > 90)) && ((c < 97) || (c > 122)))
   {
      return 0;
   }
   return 1;
}

uint8_t CharToInt(char c)
{
   if(c < '0' || c > '9')
   {
      return -1;
   }

   return (uint8_t)(c-'0'); 
}

uint32_t StringToInt(const char s[])
{
   uint32_t  temp;
   uint32_t length = strlen(s);
   uint32_t n = (uint32_t)pow(10,(length-1));
   uint32_t number = 0;
   for(uint32_t i = 0; i < length; i++)
   {
      temp = (CharToInt(s[i]))*n;
      number += temp;
      n = n / 10;
   }
   return number;
}
