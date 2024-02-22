#include <stdio.h>
#include "Point.h"

Point Point_initialize(double x, double y)
{
    Point aPoint;
    aPoint.x = x;
    aPoint.y = y;
    return aPoint;
}

Point add(Point p1, Point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

void Print(const Point *self)
{
    printf("%f %f", self->x, self->y);
}