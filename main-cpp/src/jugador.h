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
    static int cant_de_jugadores = 0;
    int id;
    int lvl;
    Carta mano[3];
    string nombre;
    string descripcion;
    Sexo sexo;
    Stats estadisticas;
    Item inventario[50]; //Por ahora lo limito
public:
    Jugador();
    Jugador(string nombre, string descripcion, Sexo sexo);
    void setCartas(Carta carta1, Carta carta2, Carta carta3);
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
    this->estadisticas.dinero = 0.0f;
    this->estadisticas.xp = 0;
    this->estadisticas.A_agresividad = Atributo("Agresividad", MuyBajo);
    this->estadisticas.A_mentiroso = Atributo("Mentiroso", MuyBajo);
    this->estadisticas.A_pescador = Atributo("Pescador", MuyBajo);
    this->estadisticas.A_tramposo = Atributo("Tramposo", MuyBajo);
}

void Jugador::setCartas(Carta carta1, Carta carta2, Carta carta3)
{
    this->mano[0] = Carta(carta1);
    this->mano[1] = Carta(carta2);
    this->mano[2] = Carta(carta3);
}
#endif
