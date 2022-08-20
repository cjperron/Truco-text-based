#ifndef STATS_H
#define STATS_H

#include"truco.h"

using std::string;

class Atributo
{
private:
    string nombre;
    Nivel estado;
    int xp_interna;
public:
    Atributo(const string nombre, Nivel estado);
    Atributo();
    Atributo operator=(const Atributo &atributo);
    Atributo& setEstado(Nivel estado);
    Atributo& setXpInterna(int xp);
    Atributo& setNombre(string nombre);

    string sgetEstado();

    string toString();
};

class Stats
{
private:
    unsigned long xp;
    double dinero;
    Atributo A_mentiroso;
    Atributo A_pescador;
    Atributo A_agresividad;
    Atributo A_tramposo;
public:
    Stats();
    
    Stats operator=(const Stats &estadisticas);
    Stats& setDinero(double x);
    Stats& setXp(unsigned long xp);
    
    double getDinero();
    unsigned long getXp();
    string toString();
};


#endif
