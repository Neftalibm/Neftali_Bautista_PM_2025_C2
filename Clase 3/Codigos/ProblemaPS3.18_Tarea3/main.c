#include <stdio.h>

int main() {
int N, i, j;

printf("Ingrese un numero entero positivo: ");
scanf("%d", &N);

for (i = N; i >= 1; i--) {

    for (j = 1; j <= i; j++) {
        printf("%d ", j);
}

for (j = i; j >= 1; j--) {
    printf("%d ", j);
}
printf("\n");
    }

return 0;
}
