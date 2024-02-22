#include <stdio.h>
#include <stdint.h>

typedef struct Point
{
    double x;
    double y;
} Point;

void Print(const Point *self)
{
    printf("%.2f %.2f", self->x, self->y);
}

Point add(Point p1, Point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

int main()
{
    Point a = {1.0, 2.0};
    Point b = {3.0, 4.0};
    Point c = add(a,b);
    
    printf("%f %f %f", a.x, b.x, c.x);
    return 0;  
}