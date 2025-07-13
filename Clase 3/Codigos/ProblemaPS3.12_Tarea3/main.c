#include <stdio.h>

int main() {
int NUM;

// Leer número
printf("Ingrese un numero entero positivo: ");
scanf("%d", &NUM);

// Validar que el número sea mayor que 2
if (NUM <= 2) {
printf("No hay numeros primos menores que %d.\n", NUM);
}
else {
    printf("Numeros primos menores que %d:\n", NUM);

    for (int i = 2; i < NUM; i++) {
    int esPrimo = 1; // Asumimos que i es primo
    for (int j = 2; j * j <= i; j++) {
    if (i % j == 0) {
    esPrimo = 0;
break;
}
}

if (esPrimo) {
printf("%d ", i);
}
}
printf("\n");
    }

return 0;
}
