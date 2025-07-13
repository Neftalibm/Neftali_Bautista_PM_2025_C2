#include <stdio.h>
#include <stdlib.h>

int F1(void);
int F2(void);
int F3(void);
int F4(void);

int K =3;

void main(void)
{
int I;
for (I=1; I<=3; I++)
{
    printf("\nEl resultado de la funcion F1 es: %d", F1());
    printf("\nEl resultado de la funcion F2 es: %d", F2());
    printf("\nEl resultado de la funcion F3 es: %d", F3());
    printf("\nEl resultado de la funcion F4 es: %d", F4());
}
}

int f1(void)
{
int K=5;
K=K+::K
return(K);
}
