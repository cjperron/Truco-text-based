#include "truco.h"
#include<string.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void mypause(void)
{
    printf("Press [Enter] to continue . . .");
    fflush(stdout);
    getchar();
}

int main(int argc, char *argv[])
{
    string buffer = "1";
    // Inicializaciones de constructores.......

    // --
    do
    {
        system("clear");
        if (!isdigit(buffer[0]))
            cout << KRED << "Error no reconocido\t" << KNRM;
        cout<< KGRN << "T  R  U  C  O\t\t" << KCYN << "Unix version\n"
            << KWHT << "1. Jugar\n2. Opciones\n3. Salir\n"
            << KNRM << endl;
        do
        {
            cout << ">>";
            cin >> buffer;
        } while (buffer.length() > 1);
        switch (buffer[0])
        {
        case '1':
            // Aca sale el menu de juego.
            menuDeJuego();
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