#include"stats.h"
//Atributo.
Atributo Atributo::operator=(const Atributo &atributo)
{
    this->nombre = atributo.nombre;
    this->estado = atributo.estado;
    this->xp_interna = atributo.xp_interna;
    return *this;
}
Atributo::Atributo(const string nombre, Nivel estado)
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
//Stats
Stats& Stats::setDinero(double x)
    {
        this->dinero = dinero;
        return *this;
    }
Stats& Stats::setXp(unsigned long xp)
{
    this->xp = xp;
    return *this;
}
Stats::Stats()
{
    //Todo arranca en 0.
    this->dinero = 0.0f;
    this->xp = 0;
    this->A_agresividad = Atributo("Agresividad", MuyBajo);
    this->A_mentiroso = Atributo("Mentiroso", MuyBajo);
    this->A_pescador = Atributo("Pescador", MuyBajo);
    this->A_tramposo = Atributo("Tramposo", MuyBajo);
}
Stats Stats::operator=(const Stats &estadisticas)
{
    this->A_agresividad = estadisticas.A_agresividad;
    this->A_mentiroso = estadisticas.A_mentiroso;
    this->A_pescador = estadisticas.A_pescador;
    this->A_tramposo = estadisticas.A_tramposo;
    this->dinero = estadisticas.dinero;
    this->xp = estadisticas.xp;
    return *this;
}
