#include "carta.h"
// Getters
bool Carta::getGanaRonda()
{
    return gana_ronda;
}
string Carta::getNombre()
{
    return nombre;
}
Palo Carta::getPalo()
{
    return palo;
}
int Carta::getValor()
{
    return valor;
}
// Setters
void Carta::setGanaRonda(bool gana_ronda)
{
    this->gana_ronda = gana_ronda;
}
void Carta::setNombre(string nombre)
{
    this->nombre = nombre;
}
void Carta::setPalo(Palo palo)
{
    this->palo = palo;
}
void Carta::setValor(int valor)
{
    this->valor = valor;
}
//Constructor default.
Carta::Carta(Palo palo, int valor, string nombre)
{
    this->palo = palo;
    this->valor = valor;
    this->nombre = nombre;
}
//Copia de otra clase carta.
Carta::Carta(Carta carta)
{
    this->nombre = carta.nombre;
    this->palo = carta.palo;
    this->valor = carta.valor;
}
//Devolver el palo como string.
string Carta::sgetPalo(Palo palo)
{
    switch(palo)
    {
        case Espada:
            return "Espada";
        case Basto:
            return "Basto";
        case Oro:
            return "Oro";
        case Copa:
            return "Copa";
        default:
            return nullptr;
    }
    return nullptr;
}
//Metodo toString()
string Carta::toString()
{
    return "Carta {nombre: "+this->nombre+" , palo: "+sgetPalo(this->palo)+" , valor: "+this->valor+" }";
}
