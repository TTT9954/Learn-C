#include <stdio.h>
#include "Point.h"

Point Point_initialize(double x, double y)
{
    Point aPoint = {x, y};
    return aPoint;
}

void Point_offset(Point *self, const Point *offset_by)
{
    self->x = offset_by->x;
    self->y = offset_by->y;
}

Point add(Point p1, Point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

void Print(const Point *self)
{
    printf("%f %f\n", self->x, self->y);
}