#ifndef JUGADOR_H
#define JUGADOR_H

#include"item.h"
#include"carta.h"
#include"stats.h"
#include"truco.h"

using std::string;
class Jugador
{
private:
    int id;
    int lvl;
    Carta mano[3];
    string nombre;
    string descripcion;
    Sexo sexo;
    Stats estadisticas;
    Item inventario[50]; //Por ahora lo limito
public:
    static int cant_de_jugadores;
    Jugador();
    Jugador(string nombre, string descripcion, Sexo sexo);
    void setCartas(Carta carta1, Carta carta2, Carta carta3);
    static int getCantJugadores()
    {
        return cant_de_jugadores;
    }
};

Jugador::Jugador()
{
    this->id = cant_de_jugadores;
    cant_de_jugadores++;
    this->lvl = 0;
}

Jugador::Jugador(string nombre, string descripcion, Sexo sexo)
{
    this->id = this->cant_de_jugadores;
    cant_de_jugadores++;
    this->lvl = 0;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->sexo = sexo;
    this->estadisticas.A_agresividad.setNombre("Agresividad");
    this->estadisticas.A_mentiroso.setNombre("Mentiroso");
    this->estadisticas.A_pescador.setNombre("Pescador");
    this->estadisticas.A_tramposo.setNombre("Tramposo");
}

void Jugador::setCartas(Carta carta1, Carta carta2, Carta carta3)
{
    this->mano[0] = carta1;
    this->mano[1] = carta2;
    this->mano[2] = carta3;
}

int Jugador::cant_de_jugadores = 0;
#endif
