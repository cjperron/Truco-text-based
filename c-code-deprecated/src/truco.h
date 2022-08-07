#ifndef TRUCO_H
#define TRUCO_H

#include <stdio.h>  //Jaja, todo
#include <stdlib.h> // malloc()
#include <string.h> // Para ahorrar laburo
#include <time.h>   // Para manejar el tiempo.
#include <errno.h>
#include <ctype.h> // tolower(), principalmente
#include <unistd.h>
//#include <windows.h> // Claramente para la version de windows.
//#include <conio.h> //Para kbhit().
#include <stdbool.h> //Para bool.
#include"defines.h"
#define CANT_CARTAS_TRUCO 40
#define CANT_OPCIONES 3

#define FILE_JUGADORES "../bin/jugadores.truco"
#define FILE_MAZO "../bin/mazo.truco"
#define FILE_LOG "../log.txt"
#define FILE_TOTAL "../bin/sensitive_data.dat"
#define FILE_PJ_SEL "../bin/pj_seleccionado.truco"
#define FILE_OPTION "../bin/options.truco"
#define RUTA_PLAYERS "../players/"

#define espera()        \
    {                   \
        myflush(stdin); \
        mypause();      \
    }


//  menuDeJuego.c
void menuDeJuego(Carta *mazo, Jugador* pj_seleccionado);

//  mazos.c
Carta *crearMazo(void);
Carta *mezclarMazo(Carta *mazo);
Carta *leerMazo(void);
void debugMostrarMazo(Carta *mazo);

//  personajes.c
void crearPersonaje(void);
//Tengo que tirar realloc para agrandar la memoria de los jugadores, para fittearlo al archivo.
Jugador *leerPersonajes(void);
void mostrarPersonajes(void);
Jugador *seleccionar_pj(Jugador* lista_de_jugadores); //Selecciona el personaje a usar.
Jugador *devolver_pj(Jugador *lista_de_jugadores, int id); //Devuelve el numero de personaje especificado.
int devolver_total_jugadores(void);
int write_total_jugadores(int total);
Jugador *devolver_pj_seleccionado(void);

//Escribe todos los datos del jugador en un archivo separado
int writeSeparatePlayerFile(Jugador* player);
/*
deberia reescribir las funciones de personajes para que lean los personajes 1 por 1 de /personajes
y que despues de eso escriban el total en sensitive_data
*/

int addItemToPj(Jugador* jugador, Item item);
int devolver_cant_items(char* playerName);
int escribir_cant_items(char* playerName, int nItems); //if 0, todo correcto
Jugador *getPlayerByName(char* playerName); //Lee los nombres desde jugadores.truco

// En main
void myflush(FILE *in);
void mypause(void);

//En opciones.c
bool writeConfigFile(void);
Option* readConfigFile(void);
void printOptions(Option* opciones);


//Comportamientos
int removeJugadores(void);
int removeAll(void);
int ingresarCodigo(void);



#endif /* TRUCO_H */