#include <stdio.h>
#include <stdlib.h>

int main()
{
/* Incremento de precio.
El programa, al recibir como dato el precio de un producto importado,
incrementa 11% el mismo si �ste es inferior a $1,500.
PRE y NPR: variable de tipo real. */

    float PRE, NPR;

    printf("Ingrese el precio del producto: ");
    scanf("%f", &PRE);

    if (PRE < 1500)
    {
        NPR = PRE * 1.11;
        printf("\nNuevo precio: %7.2f\n", NPR);
    }
    return 0;
}
