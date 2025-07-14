#include <stdio.h>
#include <stdlib.h>

int cuenta(char *);

void main(void)
{

 int I;
 char cad[50];
 printf("\nIngrese la cadena de caracteres: ");
 gets(cad);
 I = cuenta(cad);
 printf("\nLongitud de la cadena: %d", I);
}

int cuenta(char *cadena)
{

 int c = 0;
 while(!(cadena[c] == '\0'))
      c++;
  return (c);
}
