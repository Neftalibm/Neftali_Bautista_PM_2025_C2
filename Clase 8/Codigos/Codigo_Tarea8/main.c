#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[50];
    float promedio;
} Alumno;

int main()
{
Alumno *alumno;
alumno = (Alumno *)malloc(sizeof(Alumno));

if (alumno == NULL)
{
    printf("No se pudo asignar memoria.\n");
return 1;
}


    printf("Ingrese la matricula: ");
    scanf("%d", &alumno->matricula);
    getchar();

    printf("Ingrese el nombre: ");
    fgets(alumno->nombre, 50, stdin);
    alumno->nombre[strcspn(alumno->nombre, "\n")] = '\0';

    printf("Ingrese el promedio: ");
    scanf("%f", &alumno->promedio);

    FILE *archivo = fopen("alumno.dat", "wb");
    if (archivo == NULL)
{
        printf("No se pudo abrir el archivo.\n");
        free(alumno);
        return 1;
}
    fwrite(alumno, sizeof(Alumno), 1, archivo);
    fclose(archivo);
    free(alumno);

    alumno = (Alumno *)malloc(sizeof(Alumno));
    archivo = fopen("alumno.dat", "rb");
    if (archivo == NULL)
{
        printf("No se pudo abrir el archivo para leer.\n");
        free(alumno);
return 1;
}
fread(alumno, sizeof(Alumno), 1, archivo);
fclose(archivo);
printf("\nDatos leidos del archivo:\n");
printf("Matricula: %d\n", alumno->matricula);
printf("Nombre: %s\n", alumno->nombre);
printf("Promedio: %.2f\n", alumno->promedio);

free(alumno);
return 0;
}
