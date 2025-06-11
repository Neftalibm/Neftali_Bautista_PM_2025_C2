#include <stdio.h>
/* Prueba de parámetros por referencia. */
void f1(int *); /* Prototipo de función */

int main()
{
int I, K = 4;
for (I = 1; I <= 3; I++)
{
printf("\n\nValor de K antes de llamar a la funcion: %d", ++K);
f1(&K); /* Llamada a la función, modificando K por referencia */
printf("\nValor de K después de llamar a la funcion: %d", K);
}
return 0;
}

void f1(int *R)
/* La función f1 recibe un parámetro por referencia. */
{
*R += *R;
}
