#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "carta.h"
#include "mazo.h"
#include"truco.h"
#include"jugador.h"

int menuDeJuego(Mazo* mazo, Jugador* jugador);
int menuDePersonaje(Jugador* jugador);

//PLayer handling
int readJugadorSeleccionado(Jugador* jugador);
int writeJugadorSeleccionado(Jugador* jugador);
int selectJugador(Jugador* jugador); //Printea los jugadores y devuelve el seleccionado (y lo escribe en pj_seleccionado), basado en el id que elije.
int writeJugador(Jugador* jugador);
int writeTotalJugadores(Jugador* jugador);
int readTotalJugadores(Jugador* jugador);
int crearPersonaje();

#endif