#include <stdio.h>
#include <ctype.h>
/* Decodifica.
El programa decodifica una cadena de caracteres compuesta por numeros y
letras. */

void interpreta(char *); /* Prototipo de funcion. */

int main(void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    // Eliminar el salto de linea si existe
    int i = 0;
    while (cad[i] != '\0') {
        if (cad[i] == '\n') {
            cad[i] = '\0';
            break;
        }
        i++;
    }

    interpreta(cad);
    return 0;
}

void interpreta(char *cadena)
/* Esta funcion se utiliza para decodificar la cadena de caracteres. */
{
    int i = 0, j, k;
    while (cadena[i] != '\0')
    {
        if (isalpha(cadena[i]))  /* Verifica si el caracter es una letra */
        {
            k = cadena[i - 1] - '0';
            /* Convierte el caracter anterior (un digito) a entero */

            for (j = 0; j < k; j++)
                putchar(cadena[i]);
        }
        i++;
    }
    printf("\n");
}
