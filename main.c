#include <stdint.h>
#include <stdio.h>
#include "some_codes/Point.h"
#include "inc/Point.h"
#include "inc/String.h"

Point p1 = {4,6};
int main()
{
    char a[] = "Hello";
    char b[] = "World"; 

    Print(&p1);
    printf("%d", count_char(a));
    return 0;
}

