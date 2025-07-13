#include <stdio.h>
#include <stdlib.h>

int A, B, C, D;

void funcion1(int, int *, int *);
int funcion2(int *, int);

void main(void)
{
int A;
A=1;
B=2;
C=3;
D=4;
printf("\n%d %d %d %d", A, B, C, D);
A=funcion2(&A, C);
printf("\n%d %d %d %d", A, B, C, D);
}

void funcion1(int r, int *B, int *C)
{
int D;
A=*C;
D=A+3+*B;
if (r)
{
    *B=*B+2;
    *C=*C+3;
    printf("\n%d %d %d %d", A, *B, *C, D);

}
else
{
    *B=*B+5;
    *C=*C+4;
    printf("\n%d %d %d %d", A, *B, *C, D);
}
}

int funcion2(int *D, int C)
{
int B;
A=1;
B=7;
funcion1(-1, D, &B);
printf("\n%d %d %d %d", A, B, C, *D);
C+=3;
(*D)+=2;
printf("\n%d %d %d %d", A, B, C, *D);
return(C);
}
