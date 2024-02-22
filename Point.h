#ifndef POINT_H
#define POINT_H

typedef struct Point
{
    double x;
    double y;
}Point;

/* Initialize*/
Point Point_initialize(double x, double y);

/* add 2 point*/
Point add(Point p1, Point p2);

/* Print */
void Print(const Point *self);

#endif