#include"truco.h"
using std::cin;
using std::cout;
using std::string;
using std::endl;
int menuDePersonaje()
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
                break;
            case '2':
                break;
            case '3':
                break;
            default:
                break;
        }
    } while(buffer[0] != '3');
    return 0;
}