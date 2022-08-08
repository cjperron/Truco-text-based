#ifndef MAZO_H
#define MAZO_H
#include "truco.h"
#include "carta.h"
using std::string;

class Mazo
{
private:
    Carta cartas[CANT_CARTAS_TRUCO];

public:
    Mazo(void);
    // void setCarta(int index, Carta carta);
    Carta *getCartas(void);
    void mezclarMazo(void);
    
};

Mazo::Mazo(void)
{
    int j = 1;
    string nombre;
    for (int i = 0; i < 10; i++)
    {
        while (j > 7 && j < 10)
            j++;
        nombre = j + " de Espada";
        cartas[i] = Carta(Espada, j++, nombre);
    }
    j = 1;
    for (int i = 10; i < 20; i++)
    {
        while (j > 7 && j < 10)
            j++;
        nombre = j + " de Basto";
        cartas[i] = Carta(Basto, j++, nombre);
    }
    j = 1;
    for (int i = 20; i < 30; i++)
    {
        while (j > 7 && j < 10)
            j++;
        nombre = j + " de Ospada";
        cartas[i] = Carta(Oro, j++, nombre);
    }
    j = 1;
    for (int i = 30; i < 40; i++)
    {
        while (j > 7 && j < 10)
            j++;
        nombre = j + " de Copa";
        cartas[i] = Carta(Copa, j++, nombre);
    }
}
Carta *Mazo::getCartas(void)
{
    return this->cartas;
}
void Mazo::mezclarMazo(void)
{
    return; // A desarrollar.
}


#endif