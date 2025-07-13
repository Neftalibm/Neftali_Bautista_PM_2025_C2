#include <stdio.h>
#include <stdlib.h>

int CUBO(void);
int I;

void main(void)
{
int CUB;
for (I=1; I<=10; I++) {
    CUB=CUBO();
    printf("\nEl cubo de %d es: %d", I, CUB);
}
}

int CUBO(void)
{
return(I*I*I);
}
