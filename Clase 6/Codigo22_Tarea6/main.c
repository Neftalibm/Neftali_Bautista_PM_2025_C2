#include <stdio.h>
#include <string.h>

/* Escuela.
El programa genera informacion importante de los alumnos de una escuela. */

typedef struct {
    char mat[20]; // Materia
    int pro;      // Promedio
} matpro;

typedef struct {
    int matri;        // Matricula
    char nom[20];     // Nombre del alumno
    matpro cal[5];    // Arreglo de materias y promedios
} alumno;

void Lectura(alumno*, int);
void F1(alumno*, int);
void F2(alumno*, int);
void F3(alumno*, int);

int main(void) {
    alumno ALU[50];
    int TAM;

    do {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    Lectura(ALU, TAM);
    F1(ALU, TAM);
    F2(ALU, TAM);
    F3(ALU, TAM);

    return 0;
}

void Lectura(alumno A[], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\nIngrese los datos del alumno %d", I + 1);
        printf("\nIngrese la matricula del alumno: ");
        scanf("%d", &A[I].matri);
        fflush(stdin);
        printf("Ingrese el nombre del alumno: ");
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        A[I].nom[strcspn(A[I].nom, "\n")] = '\0'; // Eliminar salto de linea

        for (J = 0; J < 5; J++) {
            printf("\tMateria %d: ", J + 1);
            fflush(stdin);
            fgets(A[I].cal[J].mat, sizeof(A[I].cal[J].mat), stdin);
            A[I].cal[J].mat[strcspn(A[I].cal[J].mat, "\n")] = '\0';

            printf("\tPromedio %d: ", J + 1);
            scanf("%d", &A[I].cal[J].pro);
        }
    }
}

void F1(alumno A[], int T) {
    int I, J;
    float SUM;
    for (I = 0; I < T; I++) {
        printf("\nMatricula del alumno : %d", A[I].matri);
        SUM = 0.0;
        for (J = 0; J < 5; J++)
            SUM += A[I].cal[J].pro;
        SUM /= 5;
        printf("\tPromedio: %.2f", SUM);
    }
}

void F2(alumno A[], int T) {
    int I;
    printf("\nAlumnos con calificacion mayor a 9 en la tercera materia:");
    for (I = 0; I < T; I++) {
        if (A[I].cal[2].pro > 9)
            printf("\nMatricula del alumno : %d", A[I].matri);
    }
}

void F3(alumno A[], int T) {
    int I;
    float SUM = 0.0;
    for (I = 0; I < T; I++)
        SUM += A[I].cal[3].pro;
    SUM /= T;
    printf("\n\nPromedio de la cuarta materia: %.2f", SUM);
}
