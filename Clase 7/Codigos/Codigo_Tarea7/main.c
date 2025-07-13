#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nombre[50];
    float promedio; //guardar datos
} Alumno;

void guardarAlumnos(const char *archivo, Alumno alumnos[], int n) {
    FILE *fp = fopen(archivo, "wb");
    if (fp == NULL) {
        perror("No se pudo abrir el archivo");
        return;
    }
    fwrite(alumnos, sizeof(Alumno), n, fp);
    fclose(fp);
}

int leerAlumnos(const char *archivo, Alumno alumnos[]) {
    FILE *fp = fopen(archivo, "rb");
    if (fp == NULL) {
        perror("No se pudo abrir el archivo");
        return 0;
    }
    int count = fread(alumnos, sizeof(Alumno), MAX, fp);
    fclose(fp);
    return count;
}

void bubbleSortNombre(Alumno alumnos[], int n) {
    for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
    if (strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0) {
    Alumno temp = alumnos[j];
    alumnos[j] = alumnos[j + 1];
    alumnos[j + 1] = temp;
}
}
}
}

void bubbleSortPromedio(Alumno alumnos[], int n) {
    for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
    if (alumnos[j].promedio > alumnos[j + 1].promedio) {
    Alumno temp = alumnos[j];
    alumnos[j] = alumnos[j + 1];
    alumnos[j + 1] = temp;
}
}
}
}

void imprimirAlumnos(Alumno alumnos[], int n) {
    printf("\n%-20s | %s\n", "Nombre", "Promedio");
    for (int i = 0; i < n; i++) {
        printf("%-20s | %.2f\n", alumnos[i].nombre, alumnos[i].promedio);
    }
}

int main() {
Alumno alumnos[MAX];
int cantidad = 0;
int opcion;
char archivo[] = "alumnos.dat";

do {
    printf("\n--- MENU ---\n");
    printf("1. Ingresar alumnos\n");
    printf("2. Mostrar alumnos alfabeticamente\n");
    printf("3. Mostrar alumnos por promedio\n");
    printf("4. Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    getchar(); // limpiar buffer

if (opcion == 1) {
    printf("Cantidad de alumnos: ");
    scanf("%d", &cantidad);
    getchar();
    for (int i = 0; i < cantidad; i++) {
    printf("Nombre del alumno %d: ", i + 1);
    fgets(alumnos[i].nombre, 50, stdin);
    alumnos[i].nombre[strcspn(alumnos[i].nombre, "\n")] = '\0'; // quitar salto de línea
    printf("Promedio: ");
    scanf("%f", &alumnos[i].promedio);
    getchar();
}

guardarAlumnos(archivo, alumnos, cantidad);
        } else if (opcion == 2) {
            cantidad = leerAlumnos(archivo, alumnos);
            bubbleSortNombre(alumnos, cantidad);
            imprimirAlumnos(alumnos, cantidad);
        } else if (opcion == 3) {
            cantidad = leerAlumnos(archivo, alumnos);
            bubbleSortPromedio(alumnos, cantidad);
            imprimirAlumnos(alumnos, cantidad);
}

} while (opcion != 4);

return 0;
}
