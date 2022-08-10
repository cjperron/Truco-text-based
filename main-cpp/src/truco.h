#ifndef TRUCO_H
#define TRUCO_H

#include<iostream>
#include<fstream>
#include<string>
#include<chrono>

#define KNRM "\x1B[0m"
#define KGRY "\x1B[1;30m"
#define KRED "\x1B[1;31m"
#define KGRN "\x1B[1;32m"
#define KYEL "\x1B[1;33m"
#define KBLU "\x1B[1;34m"
#define KMAG "\x1B[1;35m"
#define KCYN "\x1B[1;36m"
#define KWHT "\x1B[1;37m"

#define CANT_CARTAS_TRUCO 40
#define CANT_OPCIONES 3

#define FILE_JUGADORES "../bin/jugadores.truco"
#define FILE_MAZO "../bin/mazo.truco"
#define FILE_LOG "../log.txt"
#define FILE_TOTAL "../bin/sensitive_data.dat"
#define FILE_PJ_SEL "../bin/pj_seleccionado.truco"
#define FILE_OPTION "../bin/options.truco"
#define RUTA_PLAYERS "../players/"

typedef enum
{
    Espada,
    Oro,
    Basto,
    Copa
} Palo;
typedef enum
{
    Masculino,
    Femenino
} Sexo;
typedef enum
{
    MuyBajo,
    Bajo,
    Normal,
    Alto,
    MuyAlto,
    Extremo,
    Maximo,
    Dios
} Nivel;

typedef enum
{
    BuenosAires,
    EntreRios,
    SantaFe,
    Cordoba,
    SantiagoDelEstero,
    Chubut,
    SantaCruz,
    TierraDelFuego,
    RioNegro,
    Mendoza,
    Tucuman,
    LaPampa,
    LaRioja,
    SanJuan,
    SanLuis,
    Formosa,
    Chaco,
    Misiones,
    Jujuy,
    Corrientes,
    Neuquen,
    Salta,
    Catamarca
} Provincia;

#endif
