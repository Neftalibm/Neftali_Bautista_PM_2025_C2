#include <stdio.h>
#include <stdlib.h>

#define TAM 100 //no funciona con const int

void Imprime(int[], int);
void Primo(int, int *);

int main()
{
int P[TAM]={1,2};
int FLA, J = 2, PRI = 3;
while (J <= TAM)
{
    FLA = 1;
    Primo(PRI, &FLA);
    if(FLA)
    {
        P[J]=PRI;
        J++;
    }
    PRI += 2;
}
Imprime(P, TAM);
    return 0;
}

void Primo(int A, int *B)
{
int DI=3;
while (*B&&(DI<(A/2)))
{
    if((A%DI)==0)
        *B=0;
}
}

void Imprime(int Primos[], int T)
{
int I;
for (I=0; I<T; I++)
printf("\nPrimos[%d]: %d", I, Primos[I]);
//no entiendo porque aparece todo en gris
}
