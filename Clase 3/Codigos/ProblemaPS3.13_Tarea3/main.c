#include <stdio.h>

int main() {
    int N1, N2, inicio, fin, i, j, esPrimo1, esPrimo2;

    printf("Ingrese el primer numero entero positivo: ");
    scanf("%d", &N1);
    printf("Ingrese el segundo numero entero positivo: ");
    scanf("%d", &N2);

    if (N1 < N2) {
        inicio = N1;
        fin = N2;
    } else {
        inicio = N2;
        fin = N1;
    }

    printf("Pares de primos gemelos entre %d y %d:\n", inicio, fin);

    for (i = inicio; i <= fin - 2; i++) {
        // Verificar si i es primo
        esPrimo1 = 1;
        if (i < 2) {
            esPrimo1 = 0;
        } else {
            for (j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    esPrimo1 = 0;
                    break;
                }
            }
        }

        // Verificar si i+2 es primo
        esPrimo2 = 1;
        if (i + 2 < 2) {
            esPrimo2 = 0;
        } else {
            for (j = 2; j * j <= i + 2; j++) {
                if ((i + 2) % j == 0) {
                    esPrimo2 = 0;
                    break;
                }
            }
        }

        // Imprimir si ambos son primos
        if (esPrimo1 && esPrimo2) {
            printf("(%d, %d)\n", i, i + 2);
        }
        else{
        }
    }

    return 0;
}
