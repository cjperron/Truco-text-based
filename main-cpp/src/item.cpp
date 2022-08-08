#include "item.h"

// Constructores
Item::Item(string codigo, string descripcion, int cantidadDisponible)
{
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->cantDisponible = cantidadDisponible;
    this->codigo = "";
}

Item::Item(string descripcion, int cantDisponible, double precio) // el de tiendas
{
    this->descripcion = descripcion;
    this->cantDisponible = cantDisponible;
    this->precio = precio;
    this->codigo = getCodigo();
}
// Metodos

// Aca se hace un codigo random, y se guarda en un binario, junto a lo que provoca el codigo.
string Item::getCodigo()
{
    if (this->codigo != "")
        return this->codigo;
    // aca se genera el codigo random, y se guarda en un archivo.
    return "NADA";
}

// Getters
int Item::getCantDisponible()
{
    return this->cantDisponible;
}

string Item::getDescripcion()
{
    return this->descripcion;
}
double Item::getPrecio()
{
    return this->precio;
}

// Setters
void Item::setCantDisponible(int cantDisponible)
{
    this->cantDisponible = cantDisponible;
}
void Item::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}
void Item::setPrecio(double precio)
{
    this->precio = precio;
}
