#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VACIO '.'

char tablero[8][8] = {
    {'r','n','b','q','k','b','n','r'},
    {'p','p','p','p','p','p','p','p'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'P','P','P','P','P','P','P','P'},
    {'R','N','B','Q','K','B','N','R'}
};

void imprimirTablero() {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < 8; i++) {
            printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
                printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void convertirPosicion(const char* pos, int* fila, int* columna) {
    *columna = tolower(pos[0]) - 'a';
    *fila = 8 - (pos[1] - '0');
}

int esBlanca(char pieza) {
    return isupper(pieza);
}

int esNegra(char pieza) {
    return islower(pieza);
}

int caminoLibre(int filaDesde, int colDesde, int filaHasta, int colHasta) {
    int pasoFila = (filaHasta - filaDesde) ? ((filaHasta - filaDesde) > 0 ? 1 : -1) : 0;
    int pasoCol = (colHasta - colDesde) ? ((colHasta - colDesde) > 0 ? 1 : -1) : 0;

    int filaActual = filaDesde + pasoFila;
    int colActual = colDesde + pasoCol;

    while (filaActual != filaHasta || colActual != colHasta) {
            if (tablero[filaActual][colActual] != VACIO) return 0;
        filaActual += pasoFila;
        colActual += pasoCol;
    }
    return 1;
}

int moverPieza(const char* desde, const char* hasta, int turnoBlanco) {
    int filaDesde, colDesde, filaHasta, colHasta;
    convertirPosicion(desde, &filaDesde, &colDesde);
    convertirPosicion(hasta, &filaHasta, &colHasta);

    if (filaDesde < 0 || filaDesde >= 8 || colDesde < 0 || colDesde >= 8 ||
        filaHasta < 0 || filaHasta >= 8 || colHasta < 0 || colHasta >= 8) {
            printf("Movimiento fuera de rango\n");
        return 0;
        }

    char pieza = tablero[filaDesde][colDesde];

    if (pieza == VACIO) {
            printf("No hay pieza en esa casilla\n");
        return 0;
    }

    // Verificar turno correcto
    if (turnoBlanco && !esBlanca(pieza)) {
            printf("Es el turno de las blancas. Solo puedes mover piezas blancas.\n");
        return 0;
    }
    if (!turnoBlanco && !esNegra(pieza)) {
            printf("Es el turno de las negras. Solo puedes mover piezas negras.\n");
        return 0;
    }

    // No permitir capturar pieza propia
    if (tablero[filaHasta][colHasta] != VACIO) {
            if (esBlanca(pieza) && esBlanca(tablero[filaHasta][colHasta])) {
                printf("No puedes capturar tu propia pieza.\n");
            return 0;
            }
        if (esNegra(pieza) && esNegra(tablero[filaHasta][colHasta])) {
                printf("No puedes capturar tu propia pieza.\n");
            return 0;
        }
    }

    int difFila = filaHasta - filaDesde;
    int difCol = colHasta - colDesde;
    int difFilaAbs = abs(difFila);
    int difColAbs = abs(difCol);

    switch (tolower(pieza)) {
    case 'p': // Peón
                    if (esBlanca(pieza)) {
                    // Movimiento simple hacia adelante
                if (difCol == 0 && difFila == -1 && tablero[filaHasta][colHasta] == VACIO) {
                        break;
                }
                // Primer movimiento puede avanzar dos casillas
                if (difCol == 0 && difFila == -2 && filaDesde == 6 && tablero[filaHasta][colHasta] == VACIO && tablero[filaDesde - 1][colDesde] == VACIO) {
                        break;
                }
                // Captura diagonal
                if (difColAbs == 1 && difFila == -1 && tablero[filaHasta][colHasta] != VACIO && esNegra(tablero[filaHasta][colHasta])) {
                        break;
                }
                printf("Movimiento invalido para peon blanco.\n");
                return 0;
                    } else { // Peón negro
                if (difCol == 0 && difFila == 1 && tablero[filaHasta][colHasta] == VACIO) {
                        break;
                }
                if (difCol == 0 && difFila == 2 && filaDesde == 1 && tablero[filaHasta][colHasta] == VACIO && tablero[filaDesde + 1][colDesde] == VACIO) {
                        break;
                }
                if (difColAbs == 1 && difFila == 1 && tablero[filaHasta][colHasta] != VACIO && esBlanca(tablero[filaHasta][colHasta])) {
                        break;
                }
                printf("Movimiento invalido para peon negro.\n");
                return 0;
                    }

    case 'r': // Torre
                    if (difFila != 0 && difCol != 0) {
                    printf("La torre se mueve solo en linea recta.\n");
                return 0;
                    }
            if (!caminoLibre(filaDesde, colDesde, filaHasta, colHasta)) {
                    printf("Hay piezas en el camino de la torre.\n");
                return 0;
            }
            break;

    case 'n': // Caballo
                    if (!((difFilaAbs == 2 && difColAbs == 1) || (difFilaAbs == 1 && difColAbs == 2))) {
                    printf("Movimiento invalido para caballo.\n");
                return 0;
                    }
            break;

    case 'b': // Alfil
                    if (difFilaAbs != difColAbs) {
                    printf("El alfil se mueve en diagonal.\n");
                return 0;
                    }
            if (!caminoLibre(filaDesde, colDesde, filaHasta, colHasta)) {
                    printf("Hay piezas en el camino del alfil.\n");
                return 0;
            }
            break;

    case 'q': // Reina
                    if (!((difFila == 0 || difCol == 0) || (difFilaAbs == difColAbs))) {
                    printf("La reina se mueve en linea recta o diagonal.\n");
                return 0;
                    }
            if (!caminoLibre(filaDesde, colDesde, filaHasta, colHasta)) {
                    printf("Hay piezas en el camino de la reina.\n");
                return 0;
            }
            break;

    case 'k': // Rey
                    if (difFilaAbs > 1 || difColAbs > 1) {
                    printf("El rey se mueve solo una casilla en cualquier direccion.\n");
                return 0;
                    }
            break;

    default:
                    printf("Pieza desconocida.\n");
            return 0;
    }

// Verificar si estás capturando un rey
if (tablero[filaHasta][colHasta] == 'k' || tablero[filaHasta][colHasta] == 'K') {
    printf("\nEl rey ha sido capturado! Fin del juego.\n");
    exit(0);
}

// Ahora sí realiza el movimiento
tablero[filaHasta][colHasta] = pieza;
tablero[filaDesde][colDesde] = VACIO;

}



int main() {
    char desde[3], hasta[3];
    int turnoBlanco = 1;
    char jugadorBlanco[50], jugadorNegro[50];

    printf("Ingrese el nombre del jugador de las BLANCAS: ");
    fgets(jugadorBlanco, sizeof(jugadorBlanco), stdin);
    jugadorBlanco[strcspn(jugadorBlanco, "\n")] = '\0';

    printf("Ingrese el nombre del jugador de las NEGRAS: ");
    fgets(jugadorNegro, sizeof(jugadorNegro), stdin);
    jugadorNegro[strcspn(jugadorNegro, "\n")] = '\0';

    printf("Juego de Ajedrez con Turnos y Reglas basicas de movimiento\n");
    printf("\nLas Mayusculas son Blancas y Minusculas Negras\n");
    imprimirTablero();

    while (1) {
            printf("Turno de %s (%s). Movimiento (ej. e2 e4, o 'xx xx' para salir): ", turnoBlanco ? jugadorBlanco : jugadorNegro, turnoBlanco ? "BLANCAS" : "NEGRAS");
        scanf("%2s %2s", desde, hasta);

        if (strcmp(desde, "xx") == 0 || strcmp(hasta, "xx") == 0) {
                printf("Saliendo del juego...\n");
            break;
        }

        if (moverPieza(desde, hasta, turnoBlanco)) {
                turnoBlanco = !turnoBlanco;
            imprimirTablero();
        } else {
            printf("Intenta de nuevo.\n");
        }
    }


    return 0;
}
