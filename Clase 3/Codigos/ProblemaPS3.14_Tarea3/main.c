#include <stdio.h>
#include <math.h>

int main() {
double x;  // �ngulo en radianes
double seno = 0.0;
double termino;
int n = 1;  // Contador de t�rminos
int signo = 1;  // Alterna entre positivo y negativo

printf("Introduce el valor de x en radianes: ");
scanf("%lf", &x);

do {
// Calcular factorial de (2n-1) directamente
double fact = 1;
for(int i = 1; i <= (2*n - 1); i++) {
            fact *= i;
}

// Calcular el t�rmino actual: x^(2n-1) / (2n-1)! * signo
termino = signo * pow(x, 2*n - 1) / fact;

// Agregar el termino a la suma
seno += termino;

// Cambiar el signo para el proximo t�rmino
signo *= -1;

// Incrementar el contador de t�rminos
n++;

} while(fabs(termino) > 0.001);  // Continuar mientras el ultimo t�rmino sea mayor que 0.001

printf("\nResultado:");
printf("\nSen(%.4f) = %.4f", x, seno);
printf("\nN�mero de t�rminos usados: %d", n-1);
printf("\nValor de la librer�a math.h: %.4f\n", sin(x));

return 0;
}
