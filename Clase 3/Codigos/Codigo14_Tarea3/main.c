#include <stdio.h>
#include <stdlib.h>

int main()
{
int VOT, C1=0, C2=0, C3=0, C4=0, C5=0, NU=0, SVO;
float PO1, PO2, PO3, PO4, PO5, PON;
printf("Ingrese el primer voto: ");
scanf("%d", &VOT);
while(VOT)
{
    switch(VOT)
    {
        case 1: C1++; break;
        case 2: C2++; break;
        case 3: C3++; break;
        case 4: C4++; break;
        case 5: C5++; break;
        default: NU++; break;
    }
    printf("Ingrese el siguiente voto -0 para terminar-: ");
    scanf("%d", &VOT);

}
SVO=C1+C2+C3+C4+C5+NU;
PO1=((float)C1/SVO)*100;
PO2=((float)C1/SVO)*100;
PO3=((float)C1/SVO)*100;
PO4=((float)C1/SVO)*100;
PO5=((float)C1/SVO)*100;
PON=((float)C1/SVO)*100;
printf("\nTotal de votos: %d", SVO);
printf("\n\nCandidato 1: %d votos .. Porcentaje: %5.2f", C1, PO1);
printf("\nCanditato 2: %d votos .. Porcentaje: %5.2f", C2, PO2);
printf("\nCanditato 3: %d votos .. Porcentaje: %5.2f", C3, PO3);
printf("\nCanditato 4: %d votos .. Porcentaje: %5.2f", C4, PO4);
printf("\nCanditato 5: %d votos .. Porcentaje: %5.2f", C5, PO5);
printf("\nNulos: %d .. Porcentaje: %5.2f", NU, PON);
    return 0;
}
