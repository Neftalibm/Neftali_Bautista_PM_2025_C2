#include <stdio.h>
#include <math.h>

int main() {
double x;  // Ángulo en radianes
double seno = 0.0;
double termino;
int n = 1;  // Contador de términos
int signo = 1;  // Alterna entre positivo y negativo

printf("Introduce el valor de x en radianes: ");
scanf("%lf", &x);

do {
// Calcular factorial de (2n-1) directamente
double fact = 1;
for(int i = 1; i <= (2*n - 1); i++) {
            fact *= i;
}

// Calcular el término actual: x^(2n-1) / (2n-1)! * signo
termino = signo * pow(x, 2*n - 1) / fact;

// Agregar el termino a la suma
seno += termino;

// Cambiar el signo para el proximo término
signo *= -1;

// Incrementar el contador de términos
n++;

} while(fabs(termino) > 0.001);  // Continuar mientras el ultimo término sea mayor que 0.001

printf("\nResultado:");
printf("\nSen(%.4f) = %.4f", x, seno);
printf("\nNúmero de términos usados: %d", n-1);
printf("\nValor de la librería math.h: %.4f\n", sin(x));

return 0;
}
