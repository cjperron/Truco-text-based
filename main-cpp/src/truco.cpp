#include "truco.h"
#include"mazo.h"
using std::cin;
using std::cout;
using std::string;
using std::endl;


int menuDeJuego(Mazo* mazo)
{
    string buffer;
    // Logica de los jugadores.
    do
    {
        system("clear");
        cout << KGRN << "1. Partido vs IA\n"
            << KYEL << "2. Torneo 'San Bonifacio'\n"
            << KCYN << "3. Personaje\n"
            << KRED << "4. Salir" << KNRM << endl
            << endl;
        // Personaje seleccionado.
        do
        {
            cout << ">>";
            cin >> buffer;
        } while(isdigit(buffer[0]) && buffer.length() != 1);
        switch (buffer[0]) {
            case '1':
                // Faltaria desarrollar la IA y el partido en si.
                break;
            case '2':
                // do something
                break;
            case '3':
                menuDePersonaje();
                break;
            case '4':
                break;
            default:
                cout << KRED << "Error: No reconocido\n"<<KNRM;
                break;
        }
    } while (buffer[0] != '4');
    return 0;
}