#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int MAX=10;
void Lectura(float *, int);
double Suma(float *, int);

void main(void)
{
float VEC[MAX];
double RES;
Lectura(VEC, MAX);
RES = Suma(VEC, MAX);
printf("\n\nSuma de los cuadrados de los elementos: %.2lf", RES);
}

void Lectura(float A[], int T)
{
int I;
for (I=0; I<T; I++)
{
    printf("Ingrese el elemento %d: ", I+1);
    scanf("%f", &A[I]);
}
}

double Suma(float A[], int T)
{
int I;
double AUX=0.0;
for (I=0; I<T; I++)
    AUX += pow(A[I], 2);
return(AUX);
}
