#include <stdio.h>
#include <stdlib.h>

int main()
{
int I, NUM, CUE=0;
int ARRE[10];
for (I=0; I<10; I++)
{
    printf("Ingrese el elemento %d del arreglo: ", I+1);
    scanf("%d", &ARRE[I]);
}
printf("\n\nIngrese el numero que se va a buscar en el arreglo: ");
scanf("%d", &NUM);
for (I=0; I<10; I++)
if (ARRE[I]==NUM)
    CUE++;
printf("\n\nEl %d se encuentra %d veces en el arreglo", NUM, CUE);
return 0;
}
