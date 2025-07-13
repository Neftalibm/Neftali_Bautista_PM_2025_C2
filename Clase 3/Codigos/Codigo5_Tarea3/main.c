#include <stdio.h>
#include <stdlib.h>

int main()
{
float PAGO, SPA = 0;
printf("ingrese el primer pago:\t");
scanf("%f", &PAGO);
do {
    SPA = SPA + PAGO;
    printf("Ingrese el siguiente pago -0 para terminar-\t ");
    scanf("%f", &PAGO);
}
while (PAGO);
printf("\nEl total de pagos del mes: %.2f", SPA);
    return 0;
}
