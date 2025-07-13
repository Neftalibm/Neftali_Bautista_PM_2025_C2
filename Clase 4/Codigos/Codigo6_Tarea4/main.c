#include <stdio.h>
#include <stdlib.h>

void F1(int *);

int main()
{
int I, K = 4;
for (I=1; I<=3; I++)
{
    printf("\n\nValor de K antes de llamar a la funcion: %d", ++K);
    F1(&K);
    printf("\nValor de K despues de llamar a la funcion: %d", K);
}
    return 0;
}

void F1(int *R)
{
    *R += *R;
}
