#include <stdio.h>
#include <stdlib.h>

void MAYOR(float, float, float);

int main()
{
int I;
float GOL, PAC, CAR, AGOL = 0, APAC =0, ACAR=0;
for (I=1; I<=12; I++)
{
    printf("\nIngresa las lluvias del mes %d", I);
    printf("\nRegiones Golfo, Pacifico y Caribe: ");
    scanf("%f %f %f", &GOL, &PAC, &CAR);
    AGOL += GOL;
    APAC += PAC;
    ACAR += CAR;
}
printf("\n\nPromedio de lluvias Region Golfo: %6.2f", (AGOL/12));
printf("\n\nPromedio de lluvias Region Pacifico: %6.2f", (APAC/12));
printf("\n\nPromedio de lluvias Region Caribe: %6.2f \n", (ACAR/12));
MAYOR(AGOL, APAC, ACAR);
return 0;
}

void MAYOR(float R1, float R2, float R3)
{
    if(R1>R2)
        if(R1>R3)
        printf("\nRegion con mayor promedio: Region Golfo. Promedio: %6.2f", R1/12);
    else
        printf("\nRegion con mayor promedio: Region Caribe. Promedio: %6.2f", R3/12);
else
     if(R2>R3)
        printf("\nRegion con mayor promedio: Region Pacifico. Promedio: %6.2f", R2/12);
    else
        printf("\nRegion con mayor promedio: Region Caribe. Promedio: %6.2f", R3/12);
}

