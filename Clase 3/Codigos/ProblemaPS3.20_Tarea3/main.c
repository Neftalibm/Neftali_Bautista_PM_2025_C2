#include <stdio.h>
#include <math.h>

int main() {
int T, P, R;
int expresion;

// Se limita el rango de búsqueda para evitar cálculos innecesarios
for (T = 1; T <= 10; T++) {
    for (P = 1; P <= 20; P++) {
    for (R = 1; R <= 5; R++) {
    expresion = 7 * pow(T, 4) - 6 * pow(P, 3) + 12 * pow(R, 5);

    if (expresion < 5850) {
    printf("T = %d, P = %d, R = %d => Resultado = %d\n", T, P, R, expresion);
        }
    }
}
}

return 0;
}
