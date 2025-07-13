#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
int NUMERO;
long CUADRADO, SUMCUA=0;
printf("\nIngrese un numero entero -0 para terminar-:\t");
scanf("%d", &NUMERO);
while (NUMERO) {
    CUADRADO = pow (NUMERO, 2);
    printf("%d al cubo es %ld\n3", NUMERO, CUADRADO);
    SUMCUA = SUMCUA + CUADRADO;
    printf("ingrese un numero entero -0 para terminar-:\t");
    scanf("%d", &NUMERO);
}
printf("\nLa suma de los cuadrados es %ld", SUMCUA);
    return 0;
}
