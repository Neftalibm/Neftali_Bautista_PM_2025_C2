#include <stdio.h>
#include <stdlib.h>

int CUBO(int);

int main()
{
int I;
for (I=1; I<=10; I++)
    printf("\nEl cubo de I es: %d", CUBO(I));

    return 0;
}

int CUBO(int K)
{
    return(K*K*K);
}
