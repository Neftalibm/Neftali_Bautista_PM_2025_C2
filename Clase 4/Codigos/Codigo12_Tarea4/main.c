#include <stdio.h>
#include <stdlib.h>

int MCD(int, int);

int main()
{
int NU1, NU2, RES;
printf("\nIngresa los dos numeros enteros: ");
scanf("%d %d", &NU1, &NU2);
RES = MCD(NU1, NU2);
printf("\nEl maximo comun divisor de %d y %d es: %d", NU1, NU2, RES);

    return 0;
}
int MCD(int N1, int N2)
{
int I;
if (N1<N2)
    I=N1/2;
else
    I=N2/2;
while ((N1%I)||(N2%I))
    I--;
return I;
}
