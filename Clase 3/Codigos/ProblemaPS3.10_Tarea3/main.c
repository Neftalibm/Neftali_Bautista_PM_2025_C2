#include <stdio.h>

int main() {
float L1, L2, L3, L4, L5, L6;
int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0;
float total = 0;
int CLA, CAN;

printf("Ingrese los precios de las localidades:\n");
printf("L1: "); scanf("%f", &L1);
printf("L2: "); scanf("%f", &L2);
printf("L3: "); scanf("%f", &L3);
printf("L4: "); scanf("%f", &L4);
printf("L5: "); scanf("%f", &L5);
printf("L6: "); scanf("%f", &L6);

printf("\nIngrese las ventas:\n");

while (1) {
    printf("Lugar de venta: ");
    scanf("%d", &CLA);
     printf("Cuantas ventas: ");
    scanf("%d", &CAN);

    if (CLA == 0 && CAN == 0)
            break;

    if (CLA == 1) {
        b1 += CAN;
        total += L1 * CAN;
    } else if (CLA == 2) {
        b2 += CAN;
        total += L2 * CAN;
    } else if (CLA == 3) {
        b3 += CAN;
        total += L3 * CAN;
    } else if (CLA == 4) {
        b4 += CAN;
        total += L4 * CAN;
    } else if (CLA == 5) {
        b5 += CAN;
        total += L5 * CAN;
    } else if (CLA == 6) {
        b6 += CAN;
        total += L6 * CAN;
    } else {
        printf("Localidad invalida. Use numeros del 1 al 6.\n");
    }
}

printf("\nBoletos vendidos:\n");
printf("L1: %d\n", b1);
printf("L2: %d\n", b2);
printf("L3: %d\n", b3);
printf("L4: %d\n", b4);
printf("L5: %d\n", b5);
printf("L6: %d\n", b6);
printf("Recaudacion total: $%.2f\n", total);

return 0;
}

