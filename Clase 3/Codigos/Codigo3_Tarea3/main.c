#include <stdio.h>
#include <stdlib.h>

int main()
{
float PAGO, SPA;
SPA = 0;
printf("ingrese el primer pago:\t");
scanf("%f", &PAGO);
while (PAGO){
    SPA=SPA+PAGO;
    printf("Ingrese el siguiente pago:\t ");
    scanf("%f,", &PAGO);
}
printf("\nEl total de pagos del mes es: %.2f", SPA);
    return 0;
}
