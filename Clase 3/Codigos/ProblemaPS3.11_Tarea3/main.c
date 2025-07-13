#include <stdio.h>

int main() {
int N;
float vino1, vino2, vino3, vino4;
float total_tipo1 = 0, total_tipo2 = 0, total_tipo3 = 0, total_tipo4 = 0, total_absoluto;
float total_anual;


printf("Ingrese el numero de years (N): "); //no puedo poner la ñ jaja
scanf("%d", &N);


for (int i = 1; i <= N; i++) {
    printf("\nyear %d:\n", i);


printf("Litros de vino tipo 1: ");
scanf("%f", &vino1);
printf("Litros de vino tipo 2: ");
scanf("%f", &vino2);
printf("Litros de vino tipo 3: ");
scanf("%f", &vino3);
printf("Litros de vino tipo 4: ");
scanf("%f", &vino4);


total_tipo1 += vino1;
total_tipo2 += vino2;
total_tipo3 += vino3;
total_tipo4 += vino4;


total_anual = vino1 + vino2 + vino3 + vino4;
total_absoluto = total_tipo1+total_tipo2+total_tipo3+total_tipo4;
printf("Total producido en el year %d: %.2f litros\n", i, total_anual);
}


printf("\nTotal producido por tipo de vino:\n");
printf("Tipo 1: %.2f litros\n", total_tipo1);
printf("Tipo 2: %.2f litros\n", total_tipo2);
printf("Tipo 3: %.2f litros\n", total_tipo3);
printf("Tipo 4: %.2f litros\n", total_tipo4);

printf("\nTotal Absoluto de todos los tipos de vino:\n");
printf("Litros total: %.2f \n", total_absoluto);

return 0;
}
