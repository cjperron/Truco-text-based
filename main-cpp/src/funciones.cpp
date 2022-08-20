#include"funciones.h"
using std::cin;
using std::cout;
using std::endl;
int writeJugador(Jugador* jugador)
{
    ofstream player_file(FILE_JUGADORES, std::ios::binary | std::ios::in | std::ios::app);
    if (player_file.fail()) return 1;
    player_file.write((char*)&jugador, sizeof(jugador));
    player_file.close();
    return 0;
}
int writeTotalJugadores(Jugador* jugador)
{
    ofstream archivo_total(FILE_TOTAL, std::ios::binary | std::ios::out);
    if(archivo_total.fail()){
        archivo_total.close();
        return 1;
    }
    int p = jugador->getCantJugadores();
    //cout << "p: " << jugador.getCantJugadores() << endl;
    archivo_total.write((char *)&p, sizeof(int));
    if(archivo_total.fail()){
        archivo_total.close();
        return 2;
    }   
    archivo_total.close();
    return 0;
}
int readTotalJugadores(Jugador* jugador)
{
    ifstream archivo_total(FILE_TOTAL, std::ios::binary | std::ios::in);
    if(archivo_total.fail()) {
        archivo_total.close();
        return 1;
    }
    int p;
    archivo_total.read((char *)&p, sizeof(int));
    if(archivo_total.fail()){
        archivo_total.close();
        return 1;
    } 
    //cout << "p: " << p << endl;
    jugador->setCantJugadores(p);
    archivo_total.close();
    return 0;
}
//Copia el jugador entero al archivo.
int writeJugadorSeleccionado(Jugador* jugador)
{
    ofstream pjSel_file(FILE_PJ_SEL, std::ios::binary | std::ios::out);
    if(pjSel_file.fail()) return 1;
    pjSel_file.write((char*)jugador, sizeof(Jugador));
    if(pjSel_file.fail()) return 2;
    pjSel_file.close();
    return 0;
}
// Le escribe al *jugador el jugador seleccionado.
int readJugadorSeleccionado(Jugador* jugador)
{
    ifstream pjSel_file(FILE_PJ_SEL, std::ios::binary | std::ios::in);
    if(pjSel_file.fail()) return 1;
    pjSel_file.read((char*)jugador, sizeof(jugador));
    if(pjSel_file.fail()) return 2;
    pjSel_file.close();
    return 0;
}
// Muestra los jugadores guardados en el archivo de jugadores, y devuelve el seleccionado por id.
int selectJugador(Jugador* jugador)
{
    ifstream player_file(FILE_JUGADORES, std::ios::binary | std::ios::in);
    if(player_file.fail()) return 1;
    //Mostrar los jugadores guardados.
    for(int i = 0; i < jugador->getCantJugadores(); i++)
    {
        player_file.read((char*)jugador, sizeof(jugador));
        jugador->print();
    }
    player_file.close();
    //Seleccionar el jugador.
    int id;
    cout << "Ingrese el id del jugador que desea seleccionar: ";
    cin >> id;
    //Buscar el jugador con ese id.
    player_file.open(FILE_JUGADORES, std::ios::binary | std::ios::in);
    if(player_file.fail()) return 2;
    for(int i = 0; i < jugador->getCantJugadores(); i++)
    {
        player_file.read((char*)jugador, sizeof(jugador));
        if(jugador->getId() == id)
        {
            player_file.close();
            return writeJugadorSeleccionado(jugador);
        }
    }
    return 1;
}
// Crea un personaje nuevo. cant_jugadores++, append a archivo de jugadores.
int crearPersonaje()
{
    Jugador* jugador = new Jugador(1);
    string buffer;
    // Leer la cantidad de jugadores.
    readTotalJugadores(jugador);
    // Crear un nuevo jugador.
    jugador->setCantJugadores(jugador->getCantJugadores() + 1);
    jugador->setId(jugador->getCantJugadores());
    cout << "Ingrese el nombre del personaje: ";
    cin >> buffer;
    jugador->setNombre(buffer);
    buffer.clear();
    cout << "Ingrese descripcion: "; //Ingresar con " "
    std::getline(cin, buffer);
    jugador->setDescripcion(buffer);
    buffer.clear();
    cout << "Ingrese sexo(m/f): ";
    do
    {
    cin >> buffer;
    } while(toupper(buffer[0]) != 'm' && toupper(buffer[0]) != 'f');
    jugador->setSexo(buffer[0]);
    if(writeTotalJugadores(jugador)) return 1;
    // Escribir el jugador en el archivo de jugadores.
    if(writeJugador(jugador)) return 2;
    delete jugador;
    return 0;
}

