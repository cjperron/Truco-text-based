#ifndef MAZO_H
#define MAZO_H
#include "carta.h"

using std::string;
using std::ofstream;
using std::ifstream;

class Mazo
{
private:
    Carta cartas[CANT_CARTAS_TRUCO];
public:
    Mazo(void);
    // void setCarta(int index, Carta carta);
    Carta getCarta(int index);
    Mazo& mezclarMazo(void);
    
    string toString();
    
};


#endif