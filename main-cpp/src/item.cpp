#include "item.h"
#include"jugador.h"
#include"funciones.h"
using std::cin;
using std::cout;
using std::endl;
// Constructores
Item::Item(string codigo, string descripcion, int cantidadDisponible)
{
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->cantDisponible = cantidadDisponible;
    this->precio = 0.0f;
}
Item::Item(string descripcion, int cantDisponible, double precio) // el de tiendas
{
    this->descripcion = descripcion;
    this->cantDisponible = cantDisponible;
    this->precio = precio;
    this->codigo = getCodigo();
}
Item::Item()
{
    this->cantDisponible = 0;
    this->precio = 0.0f;
    // prueba
    // this->codigo = "ABC123";
    // this->descripcion = "Prueba";
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
Item Item::operator=(const Item &item)
{
    this->cantDisponible = item.cantDisponible;
    this->codigo = item.codigo;
    this->descripcion = item.descripcion;
    this->precio = item.precio;
    return *this;
}
string Item::toString()
{
    return "Item { codigo: " + this->codigo + ", descripcion: " + this->descripcion + ", precio: " +  std::to_string(this->precio) + ", cantidad_disponible: " + std::to_string(this->cantDisponible) + " }";
}


//Jugador
Jugador::Jugador()
{
    //primero recupero la cant de jugadores
    if(readTotalJugadores(this)){ //Lee cualquier cosa, aparentemente.
        this->setCantJugadores(1);
    } 
    cout << "total: " << getCantJugadores();
    while(true);
    // Luego recupero el jugador seleccionado previamente.
    if(readJugadorSeleccionado(this))
    {
        //No existe el archivo de pj seleccionado, o no se pudo leer.
        //Entonces, pido que cree uno.
        this->id = 1;
        this->lvl = 1;
        cout << KRED << "Se detecto que no se creo un personaje" << KNRM << endl;
        cout << KRED << "Por favor, cree uno" << KNRM << endl;
        cout << "Ingrese nombre: ";
        cin >> this->nombre;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Salteaba. . .
        cout << "Ingrese descripcion: "; //Ingresar con " "
        std::getline(cin, this->descripcion);
        cout << "Ingrese sexo (m/f): ";
        do
        {
            cin >> this->sexo;
        } while (toupper(this->sexo) != 'M' && toupper(this->sexo) != 'F');
        // Normal check, stats check, inventario check.
        //Aca se crea el archivo del pj.  HASTA ACA PONE BIEN TODO.
        if(writeJugador(this))
        {
            //No se pudo crear el archivo.
            cout << KRED << "No se pudo crear el archivo del personaje" << KNRM << endl;
            cout << KRED << "El juego se cerrara" << KNRM << endl;
            exit(1);
        }
        //guardar por defecto como pj_seleccionado
        if(writeJugadorSeleccionado(this))
        {
            //No se pudo crear el archivo.
            cout << KRED << "No se pudo crear el archivo del personaje seleccionado" << KNRM << endl;
            cout << KRED << "El juego se cerrara" << KNRM << endl;
            exit(1);
        }
        if(writeTotalJugadores(this))
        {
            //No se pudo crear el archivo.
            cout << KRED << "No se pudo crear el archivo de la cantidad de jugadores" << KNRM << endl;
            cout << KRED << "El juego se cerrara" << KNRM << endl;
            exit(1);
        }
    }
}
Jugador::Jugador(string nombre, string descripcion, char sexo)
{
    this->id = this->cant_de_jugadores;
    cant_de_jugadores++;
    this->lvl = 0;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->sexo = toupper(sexo);
    for(int i = 0;i < sizeof(inventario) / sizeof(Item) ; i++)
    {
        this->inventario[i] = Item("", "", 0);
    }
}
Jugador::Jugador(int i)
{
    this->lvl = 0;
}
void Jugador::setCartas(Carta carta1, Carta carta2, Carta carta3)
{
    this->mano[0] = carta1;
    this->mano[1] = carta2;
    this->mano[2] = carta3;
}
int Jugador::getCantJugadores()
{
    return cant_de_jugadores;
}
Jugador Jugador::operator=(const Jugador &jugador)
{
    this->nombre = jugador.nombre;
    this->sexo = jugador.sexo;
    this->lvl = jugador.lvl;
    this->id = jugador.id;
    this->descripcion = jugador.descripcion;
    return *this;
}
string Jugador::toString()
{
    string str = "Jugador { id: " + std::to_string(this->id) + ", lvl: " + std::to_string(this->lvl) + ",\nMano:\n1. " + this->mano[0].toString() + ",\n2. "+ this->mano[1].toString() + ",\n3. "+this->mano[2].toString() + ",\nnombre: " + this->nombre + ", descripcion: " + this->descripcion + ", Sexo: ";
    str += this->sexo;
    str += ",\nEstadisticas:\n" + this->estadisticas.toString() + "\nInventario:\n";
    for(int i = 0; i<50;i++)
    {
        str += this->inventario[i].toString();
        str += '\n';
    }
    return str;
}
int Jugador::getId()
{
    return this->id;
}
int Jugador::getLvl()
{
    return this->lvl;
}
Carta* Jugador::getMano()
{
    return this->mano;
}
const char* Jugador::getNombre()
{
    return this->nombre.data();
}
const char* Jugador::getDescripcion()
{
    return this->descripcion.data();
}
char Jugador::getSexo()
{
    return this->sexo;
}

void Jugador::setId(int id)
{
    this->id = id;
}

void Jugador::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Jugador::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

void Jugador::setSexo(char sexo)
{
    this->sexo = sexo;
}

void Jugador::setCantJugadores(int valor)
{
    cant_de_jugadores = valor;
}
int Jugador::cant_de_jugadores = 0; 

void Jugador::print()
{
    cout << "[id: " << KMAG << this->id << KNRM << "]" << endl;
    cout << "Nombre: " << KWHT << this->nombre << KNRM << endl;
    cout << "Descripcion: " << this->descripcion << endl;
    cout << "Sexo: " << this->sexo << endl;
    cout << "Lvl: " << KGRN << this->lvl << KNRM << endl;
    /*cout << "Cartas: " << endl; //dudoso
    for (int i = 0; i < 3; i++)
    {
        cout << "Carta " << i + 1 << ": " << endl;
        this->mano[i].print();
    }
    cout << "Estadisticas: " << endl;
    this->estadisticas.print();
    cout << "Inventario: " << endl;
    for (int i = 0; i < sizeof(inventario) / sizeof(Item); i++)
    {
        cout << "Item " << i + 1 << ": " << endl;
        this->inventario[i].print();
    } */
    cout << "---------------------------------" << endl;
}