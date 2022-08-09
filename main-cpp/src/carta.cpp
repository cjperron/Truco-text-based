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
    total_cartas++;
    this->palo = palo;
    this->valor = valor;
    this->nombre = nombre;
    this->gana_ronda = false;
}
//Copia de otra clase carta.
Carta::Carta(const Carta& carta)
{
    total_cartas++;
    this->nombre = carta.nombre;
    this->palo = carta.palo;
    this->valor = carta.valor;
    this->gana_ronda = false;
}
Carta::Carta()
{
    total_cartas++;
    this->nombre = "";
    this->palo = Espada;
    this->valor = 1;
    this->gana_ronda = false;
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
    return "Carta {nombre: "+this->nombre+" , palo: "+ sgetPalo(this->palo) +" , valor: "+std::to_string(this->valor)+" }";
}
int Carta::total_cartas = 0;