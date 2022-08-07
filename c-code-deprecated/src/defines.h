#ifndef DEFINES_H
#define DEFINES_H
#include <stdbool.h>
typedef enum
{
    Espada,
    Oro,
    Basto,
    Copa
} Palo;
typedef enum
{
    Gana,
    Pierde
} Ronda;
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

typedef struct
{
    Palo palo;
    int valor;
    Ronda ronda;
    char nombre[30];
} Carta;

typedef struct
{
    const char nombre[20];
    Nivel estado;
    int xp_interna;
} Atributo;

typedef struct
{
    unsigned long xp;
    Atributo mentiroso;
    Atributo pescador;
    Atributo agresividad;
    Atributo tramposo;
    double dinero;
} Stats;
typedef struct
{
    char tipo[21];
    Codigo codigo;
    int cantDisponible;
    double precio;
} Item;
typedef struct
{
    int id;
    Carta mano[3];
    char nombre[60 + 1];
    char descripcion[101];
    Sexo sexo;
    // --- Esta es la parte interesante. ---
    Stats estadisticas;
    Item* inventario;
} Jugador;
typedef struct{
    char codigo[21];
    void (*accion)(Jugador*); //Si tiene un item de Boss, se desbloquea el boss.
} Codigo ;



typedef struct
{
    Jugador *Player1;  // No modificar el puntero
    Jugador *Oponente; // No modificar el oponente
    Carta *mazo;       // Pasar el mazo creado al inicio.
    int puntosJugadorUno;
    int puntosOponente;
} Partido;

typedef struct
{
    Item *stock; // Todos los items de la tienda.
    double inflacion;
    char nombre_del_vendedor[21]; // mmm pienso poner varias tiendas en varios puntos del pais.
    int lvl;
    Provincia provincia;
} Tienda;

typedef struct{
    int id;
    char nombre[31];
    int (*comportamiento)();
} Option ; 


#endif /* DEFINES_H */