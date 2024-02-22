#include <stdio.h>
#include <stdint.h>
#include "Point.h"


int main()
{
    Point a = Point_initialize(1.0,2.0);
    Print(&a);

    return 0;  
}