#include <stdio.h>
#include <stdlib.h>

int A, B, C, D;

void funcion1(int*,int*);
int funcion2(int, int*);

int main()
{
int A;
A=1;
B=2;
C=3;
D=4;
printf("\n%d %d %d %d", A, B, C, D);
funcion1 (&B, &C);
printf("\n%d %d %d %d", A, B, C, D);
A=funcion2(C, &D);
printf("\n%d %d %d %d", A, B, C, D);
    return 0;
}

void funcion1(int*B, int*C)
{
int D;
A=5;
D=3;
(*B)++;
(*C)+=2;
printf("\n%d %d %d %d", A, *B, *C, D);
}

int funcion2(int C, int *D)
{
int B;
A++;
B=7;
C+=3;
(*D)+= 2;
printf("\n%d %d %d %d", A, B, C, *D);
return(C);
}
