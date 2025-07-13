#include <stdio.h>

// Función que determina si n es primo y guarda el resultado en *resultado
void esPrimo(int n, int *resultado) {
int i;
*resultado = 1;
if (n < 2) {
    *resultado = 0;
} else {
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            *resultado = 0;
                break;
            }
        }
    }
}

int main() {
int N1, N2, inicio, fin, i;
int primo_i, primo_i2;

printf("Ingrese el primer numero entero positivo: ");
scanf("%d", &N1);
printf("Ingrese el segundo numero entero positivo: ");
scanf("%d", &N2);

if (N1 < N2) {
    inicio = N1;
    fin = N2;
}
else {
    inicio = N2;
    fin = N1;
}

printf("Pares de primos gemelos entre %d y %d:\n", inicio, fin);

for (i = inicio; i <= fin - 2; i++) {
    esPrimo(i, &primo_i);
    esPrimo(i + 2, &primo_i2);

    if (primo_i && primo_i2) {
        printf("(%d, %d)\n", i, i + 2);
    }
}

return 0;
}
