#ifndef CARTA_H
#define CARTA_H
#include "truco.h"
using std::string;
using std::ifstream;
using std::ofstream;

class Carta
{
private:
    Palo palo;
    int valor;
    bool gana_ronda; // Si gano o no
    string nombre;   // En reemplazo de char[]
    //Cuando se copia una carta, se escribe en el archivo.
    
public:
    ~Carta();
    Carta operator=(const Carta &carta);
    static int total_cartas;
    Carta(Palo palo, int valor, string nombre); // La ronda no es necesaria
    Carta(const Carta& carta); //En caso de copiar :)
    Carta();
    // Setters
    void setPalo(Palo palo);
    void setValor(int valor);
    void setGanaRonda(bool gana_ronda);
    void setNombre(string nombre);
    // Getters
    Palo getPalo(void);
    int getValor(void);
    bool getGanaRonda(void);
    string getNombre(void);
    // Metodos
    string toString();
    string sgetPalo(Palo palo);
    static bool getCanBeRead();
    
};


#endif