#ifndef ITEM_H
#define ITEM_H

#include<string>
using std::string;
class Item
{
private:
    string descripcion;
    string codigo; //tipo "ABC123".
    int cantDisponible;
    double precio;
    //quedaria tener el comportamiento del item aca
    
public:
    //1 sobrecarga, 1 para el jugador, otra para la tienda.
    Item();
    Item(string codigo, string descripcion, int cantidadDisponible);
    Item(string descripcion, int cantDisponible, double precio);
    Item operator=(const Item &item);
    //Getters
    string getCodigo();
    string getDescripcion();
    int getCantDisponible();
    double getPrecio();

    //Setters
    void setCodigo(string codigo);
    void setDescripcion(string descripcion);
    void setCantDisponible(int cantDisponible);
    void setPrecio(double precio);
    //No hay de codigo ya que se genera uno random, y no deberia ser "customizable".

    // Metodos
    string devolverCodigoRandom(void);

};

#endif