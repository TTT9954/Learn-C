#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>

struct Phanso
{
    int tuso;
    int mauso;
};
typedef struct Phanso PS;

void Input(PS *ps)
{
    printf("Numerator: ");
    scanf("%d", &ps->tuso);
    do
    {
      printf("Denominator: ");
      scanf("%d", &ps->mauso);
    } while (ps->mauso == 0);   
}

void Output(PS ps)
{
    if(ps.mauso == ps.tuso) printf("%d",1);
    else if(ps.tuso == 0) printf("%d",0);
    else if(ps.mauso < 1) printf("%d/%d", ps.tuso*-1, ps.mauso*-1);
    else if(ps.mauso == 1) printf("%d", ps.tuso);
    else printf("%d/%d", ps.tuso, ps.mauso);
}

struct fraction
{
    struct Phanso p_s;
}ps1, ps2;

void Sum(PS ps1,PS ps2)
{
    PS sum;
    sum.tuso = ps1.tuso*ps2.mauso + ps2.tuso*ps1.mauso;
    sum.mauso = ps1.mauso*ps2.mauso;
    printf("\n\nSum of 2 fractions: ");
    Output(sum);
}

void Multiply(PS ps1,PS ps2)
{
    PS multiplier;
    multiplier.tuso = ps1.tuso*ps2.tuso;
    multiplier.mauso = ps1.mauso*ps2.mauso;
    printf("\n\nMultiply of 2 fractions: ");
    Output(multiplier);
}

int main()
{
    PS ps1,ps2;
    //struct fraction ps1,ps2;
    printf("1.fraction\n");
    Input(&ps1);
    printf("\n2.fraction\n");
    Input(&ps2);
    printf("\n\nThe 1.fraction you just enter: ");
    Output(ps1);
    printf("\n\nThe 2.fraction you just enter: ");
    Output(ps2);
    Multiply(ps1,ps2);
    Sum(ps1,ps2);
    
    return 0;
}