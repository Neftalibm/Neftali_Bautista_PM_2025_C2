#include <stdio.h>

int main() {
int N, i, j;

printf("Ingrese un numero entero positivo: ");
scanf("%d", &N);


for (i = 1; i <= N; i++) {
for (j = 1; j <= i; j++) {
    printf("%d ", j);
}
printf("\n");
}


for (i = N - 1; i >= 1; i--) {
    for (j = 1; j <= i; j++) {
        printf("%d ", j);
}
printf("\n");
}

return 0;
}
