#include <stdio.h>
#include <stdlib.h>

int MULTI(int, int);

int main()
{
int NU1, NU2, RES;
printf("\nIngresa los dos numeros: ");
scanf("%d %d", &NU1, &NU2);
RES=MULTI(NU1, NU2);
if (RES)
    printf("\nEl segundo numero es multiplo del primero");
else
    printf("\nEl segundo numero no es multiplo del primero");
    return 0;
}

int MULTI(int N1, int N2)
{
int RES;
if ((N2 % N1) ==0)
    RES=1;
else
    RES=0;
return(RES);
}
