#include <stdio.h>

int main() {
int i, j, N = 10;

for (i = 1; i <= N; i++) {
    int num = i;

// Parte ascendente
for (j = 1; j <= i; j++) {
    printf("%d ", num % 10);
    num++;
        }

// Parte descendente
num -= 2; // Regresamos dos pasos: uno extra porque ya se incrementó en el último ciclo
for (j = 1; j < i; j++) {
printf("%d ", num % 10);
num--;
}
printf("\n");
    }

return 0;
}
