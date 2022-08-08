#ifndef TIENDA_H
#define TIENDA_H
#define MAX_STOCK_TIENDA 20

#include"truco.h"
#include"item.h"

using std::string;

class Tienda
{
private:
    Item *stock;
    double inflacion;
    string nombre_del_vendedor;
    int lvl;
    Provincia provincia;
public:
    Tienda(double inflacion, string nombre_del_vendedor, int lvl, Provincia provincia); //tienda se define con los items inicializadas;
};

Tienda::Tienda(double inflacion, string nombre_del_vendedor, int lvl, Provincia provincia)
{

}



#endif