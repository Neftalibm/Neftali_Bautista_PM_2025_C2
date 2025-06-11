#include <stdio.h>
/* Prueba de par�metros por referencia. */
void f1(int *); /* Prototipo de funci�n */

int main()
{
int I, K = 4;
for (I = 1; I <= 3; I++)
{
printf("\n\nValor de K antes de llamar a la funcion: %d", ++K);
f1(&K); /* Llamada a la funci�n, modificando K por referencia */
printf("\nValor de K despu�s de llamar a la funcion: %d", K);
}
return 0;
}

void f1(int *R)
/* La funci�n f1 recibe un par�metro por referencia. */
{
*R += *R;
}
