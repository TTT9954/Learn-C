#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};
typedef struct point Point;

struct points
{
    struct point p1;
    struct point p2;
};
typedef struct points Points;

struct rectangle
{
    struct point p1;
    struct point p2;
};
typedef struct rectangle rect;

struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int pinrect(struct point p, struct rectangle r)
{
    return (p.x >= r.p1.x && p.x < r.p2.x) && (p.y >= r.p1.y && p.y < r.p2.y);
}

int main()
{
    // double distance = 0, points_X = 0,points_Y = 0;
    Point p[10];
    rect r;
    int n;
    printf("Input number of points: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        printf("%d.point: ",i);
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    for(int i=1; i<=n; i++)
    {
        printf("%d.point: %d %d\n", i, p[i].x, p[i].y);
    }
    // points_X = pow((double)(points.p2.x-points.p1.x),2);
    // points_Y = pow((double)(points.p2.y-points.p1.y),2);
    // distance = sqrt((double)points_X+points_Y);
    // printf("point 1: %d %d\n", points.p1.x, points.p1.y);
    // printf("point 2: %d %d\n", points.p2.x, points.p2.y);
    // printf("points_X: %f\n", points_X);
    // printf("points_Y: %f\n", points_Y);
    // printf("distance: %f", distance);
    return 0;
}