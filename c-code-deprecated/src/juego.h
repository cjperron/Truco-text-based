#ifndef JUEGO_H
#define JUEGO_H
#define semilla() srand(time(NULL))

#include "defines.h"

#define KNRM "\x1B[0m"
#define KGRY "\x1B[1;30m"
#define KRED "\x1B[1;31m"
#define KGRN "\x1B[1;32m"
#define KYEL "\x1B[1;33m"
#define KBLU "\x1B[1;34m"
#define KMAG "\x1B[1;35m"
#define KCYN "\x1B[1;36m"
#define KWHT "\x1B[1;37m"

/*
Notas:
    40 cartas (el mazo)

    - Se generan oponentes que tienen mas xp que vos, con variantes random en sus stats.
    - Cuando termina el partido se suma la cantidad de plata anunciada.
    - Dependiendo del comando especificado, y de las cartas, se aumentara, o disminuira la xp_interna del atributo.


*/
// Allocates memory on the heap -- Remember to free()
char *getProvincia(Provincia provincia);
// Usa el buffer y lo copia. devuelve el address del buffer
char *sgetProvincia(Provincia provincia, char* buffer);

void generarPartido(Jugador* jugador, Jugador* oponente, Carta* mazo, Partido* partido);
//Le copia un nombre random al container.
bool cpyRandomName(char* container/* , Provincia origen */);





bool partido(Partido);
bool tienda(Tienda);
#endif