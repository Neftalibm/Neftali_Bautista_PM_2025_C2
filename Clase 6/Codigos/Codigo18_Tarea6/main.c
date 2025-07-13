#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* Cuenta palabras.
El programa calcula el numero de palabras que hay en la cadena de caracteres. */

int cuentap(char *); /* Prototipo de funcion. */

int main(void)
{
    int i;
    char fra[50];
    printf("\nIngrese la linea de texto: ");
    fgets(fra, sizeof(fra), stdin);

    // Eliminar salto de linea si existe
    int j = 0;
    while (fra[j] != '\0') {
        if (fra[j] == '\n') {
            fra[j] = '\0';
            break;
        }
        j++;
    }

    strcat(fra, " "); // Se agrega un espacio al final de la cadena
    i = cuentap(fra);
    printf("\nLa linea de texto tiene %d palabras\n", i);

    return 0;
}

int cuentap(char *cad)
/* La funcion cuenta el numero de palabras que hay en la cadena de caracteres. */
{
    int i = 0, palabras = 0;
    int en_palabra = 0;

    while (cad[i] != '\0') {
        if (!isspace(cad[i])) {
            if (!en_palabra) {
                palabras++;
                en_palabra = 1;
            }
        } else {
            en_palabra = 0;
        }
        i++;
    }
    return palabras;
}
