#ifndef JUGADOR_H
#define JUGADOR_H

#include"truco.h"
#include"carta.h"
#include"stats.h"
#include"item.h"

using std::string;
class Jugador
{
private:
    int id;
    int lvl;
    Carta mano[3];
    string nombre;
    string descripcion;
    char sexo;
    Stats estadisticas;
    Item inventario[50]; //Por ahora lo limito.
    static int cant_de_jugadores;
public:
    Jugador();
    Jugador(int i); //Exclusivo a la hora de crear.
    Jugador operator=(const Jugador &jugador);
    Jugador(string nombre, string descripcion, char sexo);
    void setCartas(Carta carta1, Carta carta2, Carta carta3);
    //Getters
    int getId(void);
    int getLvl(void);
    Carta* getMano(void);
    const char* getNombre(void);
    const char* getDescripcion(void);
    char getSexo(void);
    //Setters
    void setId(int id);
    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setSexo(char sexo);
    //Estatico
    static void setCantJugadores(int);
    static int getCantJugadores();

    //Metodos
    void print();
    string toString();
};

#endif
