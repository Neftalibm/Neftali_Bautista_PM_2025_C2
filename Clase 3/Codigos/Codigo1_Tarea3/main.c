#include <stdio.h>
int main()
{
int I;
float SALARIO, NOMINA;
NOMINA = 0;
for (I=1; I<=5; I++)
{
    printf("\Ingrese el salario del maestro%d:\t", I);
    scanf("%f", &SALARIO);
    NOMINA = NOMINA+SALARIO;
}
printf("\nEl total de la nomina es %.2f", NOMINA);
return(0);
}
