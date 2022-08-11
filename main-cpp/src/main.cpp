#include "truco.h"
#include"mazo.h"
#include"funciones.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;



int main(int argc, char *argv[])
{
    string buffer = "1";
    // Inicializaciones de constructores.......
    Mazo mazo; //Tengo el mazo.
    Jugador jugador; //El constructor revisa el seleccionado, si no hay, se asume que no existen jugadores.
    // --
    do
    {
        system("clear");
        if (!isdigit(buffer[0]))
            cout << KRED << "Error no reconocido\t" << KNRM;
        cout<< KGRN << "T  R  U  C  O\t\t" << KCYN << "Unix version\n"
            << KWHT << "1. Jugar\n2. Opciones\n3. Salir\n"
            << KNRM << endl;
        /* cout << "DEBUG: \nMazo: \n" << mazo.toString() << endl;
        cout << "Luego de mezclar:" << endl << "Mazo: \n";
        mazo.mezclarMazo();
        cout << mazo.toString() << endl; */  // ANDA
        ofstream archivo_log(FILE_LOG_MAZO);
        archivo_log << mazo.mezclarMazo().toString();
        do
        {
            cout << ">>";
            cin >> buffer;
        } while (buffer.length() > 1);
        switch (buffer[0])
        {
        case '1':
            // Aca sale el menu de juego.
            menuDeJuego(&mazo, &jugador);
            break;
        case '2':
            break;
        case '3':
            break;
        default:
            break;
        }
    } while (buffer != "3");
    system("clear");
    return 0;
}