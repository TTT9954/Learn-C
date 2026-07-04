#include "LinkedList.h"
#include "Common_Func.h"
#include "StringSelf.h"
#include <string.h>



// MAIN
int main(int argc, char *argv[]) 
{
   String_t strData;
   // Force both standard out and standard error to print instantly
    setvbuf(stdout, NULL, _IONBF, 0); 
    setvbuf(stderr, NULL, _IONBF, 0); // <--- ADD THIS LINE

   const char *s = "   Hello world   ";
   strData = initStr(s);

   // strData.data = chop_right_string(&(strData), 3);
   // chop_left_string(&(strData), 3);

   chopSpecChar2SideString(&strData, ' ');

   printf("|%s|", strData.data);
   return 0; 
}

