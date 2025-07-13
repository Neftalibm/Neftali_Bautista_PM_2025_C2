#include <stdio.h>
#include <stdlib.h>

int MAD(int);

int main()
{
int NUM, RES;
printf("\nIngresa el numero: ");
scanf("%d", &NUM);
RES=MAD(NUM);
printf("\nEl mayor divisor de %d es: %d", NUM, RES);
    return 0;
}

int MAD(int N1)
{
int I=(N1/2);
while (N1%I)
    I--;
return I;
}
