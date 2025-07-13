#include <stdio.h>

int main() {
    int i, j, N;

    printf("Ingrese el numero de filas: ");
    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N - i; j++) {
            printf("  ");
        }

        int num = i;

        for (j = 1; j <= i; j++) {
            printf("%d ", num % 10);
            num++;
        }

        num -= 2;
        for (j = 1; j < i; j++) {
            printf("%d ", num % 10);
            num--;
        }

        printf("\n");
    }

    return 0;
}
