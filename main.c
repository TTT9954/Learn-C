#include "LinkedList.h"
#include "Common_Func.h"
#include "StringSelf.h"
#include <string.h>


// MAIN
int main(int argc, char *argv[]) 
{
   FILE *f = fopen(__FILE__, "rb");
   if(f == NULL) exit(1);

   int capacity = 1024*1024;
   char *buffer = malloc(1024*1024);

   size_t size = fread(buffer, 1, capacity, f);

   String_t fileRead = 
   {
      .data = buffer, 
      .count = size
   };

   chop_by_spec_char(&fileRead, '\n');
   printf("%.*s", fileRead.count, fileRead.data);


   fclose(f);

   f = fopen("test.txt", "w+");

   String_t strData;
   String_t trimStr;
   // Force both standard out and standard error to print instantly
    setvbuf(stdout, NULL, _IONBF, 0); 
    setvbuf(stderr, NULL, _IONBF, 0);

   const char *s = "   Hello, world   ";
   strData = initStr(s);
   chop_by_spec_char(&strData, ' ');
   trimStr = trimStringByDelimiter(&strData, ',');
   printf("|%.*s|\n", strData.count, strData.data);
   printf("|%.*s|\n", trimStr.count, trimStr.data);

   size_t size_write = fwrite(strData.data, 1, strData.count, f);

   printf("%lu", size_write);


   return 0; 
}

