#include <stdio.h>
#include <string.h>

/* Hospital.
El programa genera informacion acerca de los pacientes de un hospital. */

typedef struct {
    char cal[20];   // Calle
    int num;        // Numero
    char col[20];   // Colonia
    char cp[6];     // Codigo Postal
    char ciu[20];   // Ciudad
} domicilio;

typedef struct {
    char nom[20];     // Nombre y apellido
    int edad;
    char sexo;
    int con;          // Condicion
    domicilio dom;
    char tel[11];     // Telefono
} paciente;

void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void) {
    paciente HOSPITAL[100];
    int TAM;

    do {
        printf("Ingrese el numero de pacientes: ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

void Lectura(paciente A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\n\t\tPaciente %d", I + 1);
        fflush(stdin);
        printf("\nNombre: ");
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        A[I].nom[strcspn(A[I].nom, "\n")] = '\0';

        printf("Edad: ");
        scanf("%d", &A[I].edad);
        fflush(stdin);
        printf("Sexo (F-M): ");
        scanf("%c", &A[I].sexo);
        printf("Condicion (1..5): ");
        scanf("%d", &A[I].con);
        fflush(stdin);

        printf("\tCalle: ");
        fgets(A[I].dom.cal, sizeof(A[I].dom.cal), stdin);
        A[I].dom.cal[strcspn(A[I].dom.cal, "\n")] = '\0';

        printf("\tNumero: ");
        scanf("%d", &A[I].dom.num);
        fflush(stdin);

        printf("\tColonia: ");
        fgets(A[I].dom.col, sizeof(A[I].dom.col), stdin);
        A[I].dom.col[strcspn(A[I].dom.col, "\n")] = '\0';

        printf("\tCodigo Postal: ");
        fgets(A[I].dom.cp, sizeof(A[I].dom.cp), stdin);
        A[I].dom.cp[strcspn(A[I].dom.cp, "\n")] = '\0';

        printf("\tCiudad: ");
        fgets(A[I].dom.ciu, sizeof(A[I].dom.ciu), stdin);
        A[I].dom.ciu[strcspn(A[I].dom.ciu, "\n")] = '\0';

        printf("Telefono: ");
        fgets(A[I].tel, sizeof(A[I].tel), stdin);
        A[I].tel[strcspn(A[I].tel, "\n")] = '\0';
    }
}

void F1(paciente A[], int T) {
    int I, FEM = 0, MAS = 0, TOT;
    for (I = 0; I < T; I++) {
        switch (A[I].sexo) {
            case 'F': FEM++; break;
            case 'M': MAS++; break;
        }
    }
    TOT = FEM + MAS;
    if (TOT == 0) TOT = 1; // evitar division por cero
    printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
    printf("\nPorcentaje de Mujeres: %.2f%%", (float)FEM / TOT * 100);
}

void F2(paciente A[], int T) {
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
    for (I = 0; I < T; I++) {
        switch (A[I].con) {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
        }
    }
    printf("\nNumero pacientes en condicion 1: %d", C1);
    printf("\nNumero pacientes en condicion 2: %d", C2);
    printf("\nNumero pacientes en condicion 3: %d", C3);
    printf("\nNumero pacientes en condicion 4: %d", C4);
    printf("\nNumero pacientes en condicion 5: %d", C5);
}

void F3(paciente A[], int T) {
    int I;
    printf("\nPacientes ingresados en estado de gravedad:");
    for (I = 0; I < T; I++) {
        if (A[I].con == 5) {
            printf("\nNombre: %s\tTelefono: %s", A[I].nom, A[I].tel);
        }
    }
}

