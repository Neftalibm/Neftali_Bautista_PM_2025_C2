#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
double x;
double seno = 0.0;
double termino;
int n = 1;
int signo = 1;

printf("Introduce el valor de x en radianes: ");
scanf("%lf", &x);

do {
// Calcular factorial de (2n-1)
double fact = 1;
for(int i = 1; i <= (2*n - 1); i++) {
            fact *= i;
}

termino = signo * pow(x, 2*n - 1) / fact;

seno += termino;

signo *= -1;

n++;

} while(fabs(termino) > 0.001);  // Continuar mientras el ultimo término sea mayor que 0.001

printf("\nResultado:");
printf("\nSen(%.4f) = %.4f", x, seno);
printf("\nNumero de terminos usados: %d", n-1);

return 0;
}
