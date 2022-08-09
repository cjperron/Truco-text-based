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
    Carta *getCartas(void);
    void mezclarMazo(void);
    // read() --> Carta&
    // write() --> 
    //Deprecated.
    int writeCartasToFile()
    {
        int total_de_cartas = this->cartas->total_cartas;
        ofstream archivo_mazo;
        archivo_mazo.open(FILE_MAZO, std::ios::out | std::ios::binary);
        if(archivo_mazo.fail()) return 1;
        for (int i = 0; i < total_de_cartas; i++)
        {
            archivo_mazo << this->cartas[i].getGanaRonda();
            archivo_mazo << "\n";
            archivo_mazo << this->cartas[i].getNombre().data();
            archivo_mazo << "\n";
            archivo_mazo << this->cartas[i].getPalo();
            archivo_mazo << "\n";
            archivo_mazo << this->cartas[i].getValor();
            archivo_mazo << "\n";         
        }
        if(archivo_mazo.fail()) return 1;
        archivo_mazo.close();
        return 0;
    }
    /* int readCartasFromFile()
    {
        int total_de_cartas = this->cartas->total_cartas;
        ifstream archivo_mazo;
        archivo_mazo.open(FILE_MAZO, std::ios::in | std::ios::binary);
        if(archivo_mazo.fail()) return 1;
        bool tmp_gr;
        string tmp_n;
        int tmp_pl;
        int tmp_vl;
        for (int i = 0; i < total_de_cartas; i++)
        {
            archivo_mazo >> tmp_gr;
            this->cartas[i].setGanaRonda(tmp_gr);
            archivo_mazo.getline(tmp_n.data(), 13);
            this->cartas[i].setNombre(tmp_n);
            archivo_mazo >> tmp_pl;
            this->cartas[i].setPalo((Palo)tmp_pl);
            archivo_mazo >> tmp_vl;
            this->cartas[i].setValor(tmp_vl);
        }
        return 0;
    }  */
    string toString();
    
};

Mazo::Mazo(void)
{
    int j = 1;
    for (int i = 0; i < 10; i++)
    {
        while (j > 7 && j < 10) j++;
        cartas[i].setNombre(std::to_string(j)+ " de Espada");
        cartas[i].setPalo(Espada);
        cartas[i].setValor(j++);
    }
    j = 1;
    for (int i = 10; i < 20; i++)
    {
        while (j > 7 && j < 10) j++;
        cartas[i].setNombre(std::to_string(j)+ " de Basto");
        cartas[i].setPalo(Basto);
        cartas[i].setValor(j++);
    }
    j = 1;
    for (int i = 20; i < 30; i++)
    {
        while (j > 7 && j < 10) j++;
        cartas[i].setNombre(std::to_string(j)+ " de Oro");
        cartas[i].setPalo(Oro);
        cartas[i].setValor(j++);
    }
    j = 1;
    for (int i = 30; i < 40; i++)
    {
        while (j > 7 && j < 10) j++;
        cartas[i].setNombre(std::to_string(j)+ " de Copa");
        cartas[i].setPalo(Copa);
        cartas[i].setValor(j++);
    }
    //}
}
Carta *Mazo::getCartas(void)
{
    return this->cartas;
}
void Mazo::mezclarMazo(void)
{
    return; // A desarrollar.
}
string Mazo::toString()
{
    string res = "Mazo {\n";
    for (int i = 0; i < CANT_CARTAS_TRUCO; i++)
    {
        res.append(this->cartas[i].toString()+"\n");
    }
    res.append("\n }");
    return res;
}

int menuDeJuego(Mazo* mazo);
#endif