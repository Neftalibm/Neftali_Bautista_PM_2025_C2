#include <stdio.h>
#include <stdlib.h>

int CUBO(void);
int I;

int main()
{
int CUB;
for (I=1; I<=10; I++)
{
    CUB=CUBO();
    printf("\nEl cubo de %d es: %d", I, CUB);
}
   return 0;
}

int CUBO(void){
int I = 2;
return(I*I*I);
}
