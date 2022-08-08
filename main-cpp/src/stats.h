#ifndef STATS_H
#define STATS_H

#include"truco.h"

using std::string;

class Atributo
{
private:
    const string nombre;
    Nivel estado;
    int xp_interna;
public:
    Atributo(const string nombre, Nivel, estado, int xp_interna);
    void setEstado(Nivel estado);
    void setXpInterna(int xp);
};

Atributo::Atributo(const string nombre, Nivel, estado)
{
    this->nombre = nombre;
    this->estado = estado;
    this->xp_interna = 0;
}

void Atributo::setEstado(Nivel estado)
{
    this->estado = estado;
}
void Atributo::setXpInterna(int xp)
{
    this->xp_interna = xp;
}

class Stats
{
private:
    unsigned long xp;
    Atributo A_mentiroso;
    Atributo A_pescador;
    Atributo A_agresividad;
    Atributo A_tramposo;
    double dinero;
public:
    Stats();
};

Stats::Stats()
{
    //Todo arranca en 0.
    
}

#endif
