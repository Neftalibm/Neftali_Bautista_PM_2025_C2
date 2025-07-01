#include <stdio.h>
#include <ctype.h>
/* Cuenta letras minusculas y mayusculas.
El programa, al recibir como dato una frase, determina el numero de letras
minusculas y mayusculas que existen en la frase. */
int main(void)
{
    char cad[50];
    int i = 0, mi = 0, ma = 0;

    printf("\nIngrese la cadena de caracteres (maximo 50 caracteres): ");
    fgets(cad, sizeof(cad), stdin);

    // Eliminar salto de linea si existe
    while (cad[i] != '\0') {
        if (cad[i] == '\n') {
            cad[i] = '\0';
            break;
        }
        i++;
    }

    i = 0;
    while (cad[i] != '\0') {
        if (islower(cad[i]))
            mi++;
        else if (isupper(cad[i]))
            ma++;
        i++;
    }

    printf("\n\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d\n", ma);

    return 0;
}
