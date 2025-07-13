#include <stdio.h>
/* Ordena de menor a mayor.
El programa ordena de menor a mayor en funci�n de la matr�cula, creando un
nuevo archivo, un archivo de acceso directo compuesto por estructuras y
ordenado de mayor a menor. */

typedef struct /* Declaraci�n de la estructura alumno. */
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void ordena(FILE *, FILE *); /* Prototipo de funci�n */

void main(void)
{
    FILE *ar1, *ar2;
    ar1 = fopen("ad5.dat", "r");
    ar2 = fopen("ad6.dat", "w");

    if ((ar1 != NULL) && (ar2 != NULL))
        ordena(ar1, ar2);
    else
        printf("\nEl o los archivos no se pudieron abrir");

    fclose(ar1);
    fclose(ar2);
}

void ordena(FILE *ap1, FILE *ap2)
/* Esta funci�n ordena de menor a mayor un archivo compuesto por estructuras,
en funci�n de su matr�cula, y genera un nuevo archivo. */
{
    alumno alu;
    int t, n, i;

    t = sizeof(alumno);
    fseek(ap1, 0, SEEK_END);
    n = (ftell(ap1) / t) - 1;
    /* Se obtiene el n�mero de registros que componen el archivo.
       El valor de n se usar� para posicionarnos en el archivo. */

    rewind(ap1);

    for (i = n - 1; i >= 0; i--) /* Ciclo descendente. */
    {
        fseek(ap1, i * t, SEEK_SET);
        fread(&alu, t, 1, ap1);
        fwrite(&alu, t, 1, ap2);
    }
}
