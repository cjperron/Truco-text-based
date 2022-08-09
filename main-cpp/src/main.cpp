#include "truco.h"
#include"mazo.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;



int main(int argc, char *argv[])
{
    string buffer = "1";
    // Inicializaciones de constructores.......
    Mazo mazo; //Tengo el mazo.
    // --
    do
    {
        system("clear");
        if (!isdigit(buffer[0]))
            cout << KRED << "Error no reconocido\t" << KNRM;
        cout<< KGRN << "T  R  U  C  O\t\t" << KCYN << "Unix version\n"
            << KWHT << "1. Jugar\n2. Opciones\n3. Salir\n"
            << KNRM << endl;
        // cout << "DEBUG: \nMazo: \n" << mazo.toString() << endl;
        do
        {
            cout << ">>";
            cin >> buffer;
        } while (buffer.length() > 1);
        switch (buffer[0])
        {
        case '1':
            // Aca sale el menu de juego.
            menuDeJuego(&mazo);
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