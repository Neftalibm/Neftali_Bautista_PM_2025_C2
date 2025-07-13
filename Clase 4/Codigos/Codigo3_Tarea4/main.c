#include <stdio.h>
#include <stdlib.h>

void f1(void);
int K=5;


void main(void)
{
int I;
for (I=1; I<=3; I++)
    f1();
}

void f1(void)
{
    int K=2;
    K += K;
    printf("\nEl valor de la variable local es: %d", K);
    ::K= ::K+K; /*Ni idea porque no funciona, google me dice que el operador no es valido
    y tendria que crear otra variable para hacerlo pero ese no es el punto del codigo*/
    printf("\nEl valor de la variable global es: %d", ::K);
}
