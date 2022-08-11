#include"truco.h"
#include"funciones.h"
#include"jugador.h"
using std::cin;
using std::cout;
using std::string;
using std::endl;

int menuDePersonaje(Jugador* jugador)
{
    string buffer;
    do
    {
        system("clear");
        cout << KCYN << "P E R S O N A J E\n" << KYEL << "1. Crear Personaje\n"<< KMAG << "2. Elejir personaje\n" << KGRN << "3. Salir\n\n" << KNRM;
        do
        {
            cout << ">>";
            cin >> buffer;
        } while(isdigit(buffer[0]) == 0);
        switch(buffer[0])
        {
            case '1':
                if(crearPersonaje())
                    cout << KGRN << "Personaje creado con exito\n" << KNRM;
                else
                    cout << KRED << "Error al crear el personaje\n" << KNRM;
                break;
            case '2':
                if(selectJugador(jugador))
                    cout << KGRN << "Personaje seleccionado con exito\n" << KNRM;
                else
                    cout << KRED << "Error: Personaje no existe, o ocurrio un error inesperado.\n" << KNRM;
                break;
            case '3':
                break;
            default:
                break;
        }
    } while(buffer[0] != '3');
    return 0;
}