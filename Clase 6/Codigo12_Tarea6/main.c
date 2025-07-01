#include <stdio.h>
#include <stdlib.h>
/* Suma y promedio.
El programa, al recibir como datos varias cadenas de caracteres que
contienen reales, los suma y obtiene el promedio de los mismos. */
int main(void)
{
    char c;
    char cad[50];
    int i = 0;
    float sum = 0.0;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    c = getchar();
    getchar(); // Consumir el salto de linea tras ingresar c

    while (c == 'S' || c == 's')
    {
        printf("\nIngrese la cadena de caracteres: ");
        if (fgets(cad, sizeof(cad), stdin) != NULL)
        {
            // Eliminar salto de linea si existe
            int len = 0;
            while (cad[len] != '\0')
            {
                if (cad[len] == '\n')
                {
                    cad[len] = '\0';
                    break;
                }
                len++;
            }
            sum += atof(cad);
            i++;
        }
        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        c = getchar();
        getchar(); // Consumir salto de linea
    }
    if (i > 0)
    {
        printf("\nSuma: %.2f", sum);
        printf("\nPromedio: %.2f\n", sum / i);
    }
    else
    {
        printf("\nNo se ingresaron datos.\n");
    }
    return 0;
}
