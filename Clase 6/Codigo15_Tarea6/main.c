#include <stdio.h>
/* Calcula longitud.
El programa calcula la longitud de la cadena sin utilizar la funcion strlen. */
int cuenta(char *); /* Prototipo de funcion. */

int main(void)
{
    int i;
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    // Eliminar salto de linea si existe
    int j = 0;
    while (cad[j] != '\0') {
        if (cad[j] == '\n') {
            cad[j] = '\0';
            break;
        }
        j++;
    }

    i = cuenta(cad);
    printf("\nLongitud de la cadena: %d\n", i);
    return 0;
}

int cuenta(char *cadena)
/* La funcion calcula la longitud de la cadena. */
{
    int c = 0;
    while (cadena[c] != '\0')
        c++;
    return c;
}
