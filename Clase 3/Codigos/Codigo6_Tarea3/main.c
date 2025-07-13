#include <stdio.h>
#include <stdlib.h>
//este programa calcula la nomina en general y el promedio de salarios
int main()
{
int I = 0;
float SAL, PRO, NOM=0;
printf("Ingrese el salario del maestro:\t");
scanf("%f", &SAL);
do{
    NOM = NOM + SAL;
    I = I + 1;
    printf("Ingrese el salario del maestro -0 para terminar- :\t");
    scanf("%f", &SAL);
}
while (SAL);
PRO = NOM/I;
printf("\nNomina: %.2f \t promedio de salarios: %.2f", NOM, PRO);
    return 0;
}
