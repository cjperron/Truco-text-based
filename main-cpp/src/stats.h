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
    Atributo();
    Atributo& setEstado(Nivel estado);
    Atributo& setXpInterna(int xp);
    Atributo& setNombre(string nombre);
};

Atributo::Atributo(const string nombre, Nivel, estado)
{
    this->nombre = nombre;
    this->estado = estado;
    this->xp_interna = 0;
}
Atributo::Atributo()
{
    this->estado = MuyBajo;
    this->xp_interna = 0;
}
Atributo& Atributo::setNombre(string nombre)
{
    this->nombre = nombre;
    return *this;
}

Atributo& Atributo::setEstado(Nivel estado)
{
    this->estado = estado;
    return *this;
}
Atributo& Atributo::setXpInterna(int xp)
{
    this->xp_interna = xp;
    return *this;
}

class Stats
{
private:
    unsigned long xp;
    double dinero;
public:
    Atributo A_mentiroso;
    Atributo A_pescador;
    Atributo A_agresividad;
    Atributo A_tramposo;
    
    Stats& setDinero(double x)
    {
        this->dinero = dinero;
        return *this;
    }
    Stats& setXp(unsigned long xp)
    {
        this->xp = xp;
        return *this;
    }

    Stats();
};

Stats::Stats()
{
    //Todo arranca en 0.
    this->dinero = 0.0f;
    this.xp = 0;
}

#endif
