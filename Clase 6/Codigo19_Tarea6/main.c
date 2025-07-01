#include <stdio.h>
#include <string.h>

int longitud(char *cad); /* Prototipo de funcion. */

int main(void)
{
    int i, n, l = -1, p = 0, t;
    char cad[50], FRA[20][50];

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);
    getchar(); // Limpiar salto de linea pendiente

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la linea %d de texto. Maximo 50 caracteres: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        // Eliminar el salto de linea si existe
        int j = 0;
        while (FRA[i][j] != '\0') {
            if (FRA[i][j] == '\n') {
                FRA[i][j] = '\0';
                break;
            }
            j++;
        }
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        strcpy(cad, FRA[i]);
        t = longitud(cad);
        if (t > l)
        {
            l = t;
            p = i;
        }
    }

    printf("\nLa cadena con mayor longitud es: ");
    puts(FRA[p]);
    printf("Longitud: %d\n", l);

    return 0;
}

int longitud(char *cadena)
/* Esta funcion calcula la longitud de la cadena. */
{
    int cue = 0;
    while (cadena[cue] != '\0')
        cue++;
    return cue;
}
