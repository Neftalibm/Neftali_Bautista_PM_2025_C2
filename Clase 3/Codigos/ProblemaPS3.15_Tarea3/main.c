#include <stdio.h>

int main() {
int N1, N2, a, b, temp;

printf("Ingrese el primer numero natural: ");
scanf("%d", &N1);

printf("Ingrese el segundo numero natural: ");
scanf("%d", &N2);

a = N1;
b = N2;

// Algoritmo de Euclides para calcular MCD
while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
}

printf("El Maximo Comun Divisor de %d y %d es: %d\n", N1, N2, a);

return 0;
}
