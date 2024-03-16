#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
typedef struct Person
{
    char *firstname;
    char *lastname;
    char *dateofbirth;
}Person;

typedef struct POINT
{
    int x;
    int y;
}Point;

Point initialize(int x, int y)
{
    Point point;
    point.x = x;
    point.y = y;
    return point;
}

int main()
{
    /* Person */
    /* Person person_1;
    person_1.firstname = "Tran";
    person_1.lastname = "Tu";
    person_1.dateofbirth = "05/04/1999";
    person_1.firstname = (char *)malloc(sizeof(char));
    printf("Enter first name: ");
    scanf("%s", person_1.firstname);
    printf("Name: %s %s\n", person_1.firstname, person_1.lastname);
    printf("Age : %s\n", person_1.dateofbirth); */

    /* Point */
    /* Point point_1;
    int x,y;
    printf("Enter horizontal (x): "); scanf("%d", &x);
    printf("Enter vertical (y): "); scanf("%d", &y);
    point_1 = initialize(x,y);
    printf("point: (%d,%d)\n", point_1.x, point_1.y);
    return 0; */
}