#include <stdio.h>

int main() {
int N;
float vino1, vino2, vino3, vino4;
float total_tipo1 = 0, total_tipo2 = 0, total_tipo3 = 0, total_tipo4 = 0;
float total_anual;

// Leer el número de años
printf("Ingrese el numero de years (N): "); //no puedo poner la ñ jaja
scanf("%d", &N);

// Bucle por cada año
for (int i = 1; i <= N; i++) {
    printf("\nAño %d:\n", i);

// Leer litros de cada tipo de vino en el año i
printf("Litros de vino tipo 1: ");
scanf("%f", &vino1);
printf("Litros de vino tipo 2: ");
scanf("%f", &vino2);
printf("Litros de vino tipo 3: ");
scanf("%f", &vino3);
printf("Litros de vino tipo 4: ");
scanf("%f", &vino4);

// Sumar al total de cada tipo de vino
total_tipo1 += vino1;
total_tipo2 += vino2;
total_tipo3 += vino3;
total_tipo4 += vino4;

// Calcular total anual para ese año
total_anual = vino1 + vino2 + vino3 + vino4;
printf("Total producido en el year %d: %.2f litros\n", i, total_anual);
}

// Mostrar resultados totales por tipo
printf("\nTotal producido por tipo de vino:\n");
printf("Tipo 1: %.2f litros\n", total_tipo1);
printf("Tipo 2: %.2f litros\n", total_tipo2);
printf("Tipo 3: %.2f litros\n", total_tipo3);
printf("Tipo 4: %.2f litros\n", total_tipo4);

return 0;
}
