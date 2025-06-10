#include <stdio.h>

int main() {
int N, i, j;

printf("Ingrese un numero entero positivo: ");
scanf("%d", &N);

for (i = 1; i <= N; i++) {
    // Parte ascendente: del 1 hasta i
    for (j = 1; j <= i; j++) {
        printf("%d ", j);
}

// Parte descendente: del i - 1 hasta 1
for (j = i - 1; j >= 1; j--) {
        printf("%d ", j);
}
printf("\n");
    }

return 0;
}
